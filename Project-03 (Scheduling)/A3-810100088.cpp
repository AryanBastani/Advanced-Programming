#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;

const string WITHOUT_TRANSLATOR_MASSAGE="Not Found";

typedef struct time_interval
{
	int first_time;
	int last_time;
}Time_interval;

typedef struct translator
{
	string name;
	vector<Time_interval> times;
	vector<string> languages;
}Translator;

typedef struct language
{
	string name;
	vector<Translator> translators;
}Language;

typedef struct event
{
	string name;
	Time_interval time;
	vector<Language> languages;
	bool did_translator_choose;
}Event;




int read_time(ifstream& file)
{
	int time;
    string hour_and_min;

    file>>hour_and_min;
	hour_and_min.erase(hour_and_min.begin()+2);
	time=stoi(hour_and_min);

	return(time);
}


Time_interval read_times(ifstream& file)
{
	Time_interval current_time;

	current_time.first_time = read_time(file);
	current_time.last_time = read_time(file);

	return(current_time);
}


vector<string> read_languages(ifstream& file)

{
	vector<string> languages;

	while (true)
	{
        char information_isnt_over=' ';
		if (file.get()==information_isnt_over)
		{
			string current_language;
			file >> current_language;
			languages.push_back(current_language);

			continue;
		}
		break;
	}
	return(languages);
}


vector<Language> read_event_languages(ifstream& file)
{
	vector<string> languages_name = read_languages(file);

	vector<Language> languages;
	languages.resize(languages_name.size());

	for (int language_id = 0; language_id<languages_name.size(); language_id++)
	{
		languages[language_id].name = languages_name[language_id];
	}
	return(languages);
}



vector<Translator> read_translators(ifstream& file)
{
	vector<Translator> new_translators;
	int num_of_translators;

	file >> num_of_translators;

	for (int translator_id = 0; translator_id<num_of_translators; translator_id++)
	{
		Translator current_translator;
		new_translators.push_back(current_translator);

		file >> new_translators[translator_id].name;
		new_translators[translator_id].times.push_back((read_times(file)));
		new_translators[translator_id].languages = (read_languages(file));
	}
	return(new_translators);
}


vector<Translator> find_translators(vector<Translator> translators, string language_name)
{
	Language language;
	language.name = language_name;

	for (int translator_id = 0; translator_id<translators.size(); translator_id++)
	{
		for (int language_id = 0; language_id<translators[translator_id].languages.size(); language_id++)
		{
			if (translators[translator_id].languages[language_id] == language_name)
			{
				language.translators.push_back(translators[translator_id]);
				break;
			}
		}
	}
	return(language.translators);
}


bool alphabetical(const Translator& translator1, const Translator& translator2)
{
	return(translator1.name<translator2.name);
}


vector<Event> read_events(ifstream& file)
{
	vector<Event> new_events;
	int num_of_events;

	file >> num_of_events;

	for (int event_id = 0; event_id<num_of_events; event_id++)
	{
		Event current_event;
		new_events.push_back(current_event);

		file >> new_events[event_id].name;
		new_events[event_id].time = read_times(file);
		new_events[event_id].languages = read_event_languages(file);
		new_events[event_id].did_translator_choose = false;
	}
	return(new_events);
}


bool translator_size(const Translator& translator1, const Translator& translator2)
{
	if (translator1.languages.size() == translator2.languages.size())
	{
		return(alphabetical(translator1, translator2));
	}

	return((translator1.languages.size())<(translator2.languages.size()));
}


bool does_translator_free(Time_interval event_time, Time_interval free_time)
{
	return((event_time.first_time >= free_time.first_time) &&
		(event_time.last_time <= free_time.last_time));
}


vector <Time_interval> reserve_time(Time_interval event_time, vector<Time_interval> times, int interval_id)
{
	if (times[interval_id].first_time == event_time.first_time)
	{
		if (times[interval_id].last_time == event_time.last_time)
		{
			times.erase(times.begin() + interval_id);
		}
		else
		{
			times[interval_id].first_time = event_time.last_time;
		}
	}
	else if (times[interval_id].last_time == event_time.last_time)
	{
		times[interval_id].last_time = event_time.first_time;
	}
	else
	{
		Time_interval new_interval;
		new_interval.first_time = event_time.last_time;
		new_interval.last_time = times[interval_id].last_time;

		times[interval_id].last_time = event_time.first_time;
		times.push_back(new_interval);
	}
	return(times);
}


int find_translator_id(Translator the_translator, vector<Translator> translators)
{
	for (int translator_id = 0; translator_id<translators.size(); translator_id++)
	{
		if (the_translator.name == translators[translator_id].name)
		{
			return(translator_id);
		}
	}
	return(-1);
}


vector<Translator> check_time(Event event, vector<Translator>& translators, int language_id)
{
	bool did_choose = false;
	vector <Translator> the_translators = event.languages[language_id].translators;
	int translator_id = find_translator_id(the_translators[0], translators);
	int time_size = translators[translator_id].times.size();

	for (int interval_id = 0; interval_id<time_size; interval_id++)
	{
		if (does_translator_free(event.time, translators[translator_id].times[interval_id]))
		{
			translators[translator_id].times = reserve_time(event.time,
			translators[translator_id].times, interval_id);

			did_choose = true;
			break;
		}
	}
	if (did_choose == false)
	{
		the_translators.erase(the_translators.begin());
	}
	return(the_translators);
}


bool did_translator_choose(int new_translators_size,int previous_translator_size)
{
	return(new_translators_size == previous_translator_size);
}


vector<Language> choose_translators(Event event, vector<Translator>& translators)
{
	for (int language_id = 0; language_id<event.languages.size(); language_id++)
	{
		int translator_size = event.languages[language_id].translators.size();

		for (int check_time_count = 0; check_time_count<translator_size; check_time_count++)
		{
			int new_translators_size = event.languages[language_id].translators.size();
			event.languages[language_id].translators =check_time(event, translators, language_id);

			if (did_translator_choose(new_translators_size,
			event.languages[language_id].translators.size()))
			{
				break;
			}
		}
	}
	return(event.languages);
}


bool language_size(const Language& language1, const Language& language2)
{
	if (language1.translators.size() == language2.translators.size())
	{
		return(false);
	}
	return(language1.translators.size()<language2.translators.size());
}


vector<Language> transfer_languages(vector<Language> destination, vector<Language> inputs)
{
	for (int input_id = 0; input_id<inputs.size(); input_id++)
	{
		for (int destination_id = 0; destination_id<destination.size(); destination_id++)
		{
			if (destination[destination_id].name == inputs[input_id].name)
			{
				destination[destination_id] = inputs[input_id];
				break;
			}
		}
	}
	return(destination);
}


vector<Event> translators_regulator(vector<Translator> translators, vector<Event> events)
{
	for (int event_id = 0; event_id<events.size(); event_id++)
	{
		for (int language_id = 0; language_id<events[event_id].languages.size(); language_id++)
		{
			Language current_language = events[event_id].languages[language_id];
			vector<Translator> current_translators = find_translators(translators, current_language.name);

			sort(current_translators.begin(), current_translators.end(), translator_size);

			events[event_id].languages[language_id].translators = current_translators;
		}
		Event current_event = events[event_id];

		sort(current_event.languages.begin(), current_event.languages.end(), language_size);

		current_event.languages = choose_translators(current_event, translators);

		events[event_id].languages = transfer_languages(events[event_id].languages,
		 current_event.languages);
	}
	return(events);
}


void print_result(vector<Event> events)
{
	for (int event_id = 0; event_id<events.size(); event_id++)
	{
		cout << events[event_id].name << '\n';

		for (int language_id = 0; language_id<events[event_id].languages.size(); language_id++)
		{
			cout << events[event_id].languages[language_id].name << ':' << ' ';

			if (events[event_id].languages[language_id].translators.size() != 0)
			{
				cout << events[event_id].languages[language_id].translators[0].name << '\n';
			}
			else
			{
				cout <<WITHOUT_TRANSLATOR_MASSAGE<< '\n';
			}
		}
	}
}


int main(int argc, char* argv[])
{
	vector<Translator> translators;
	vector<Event> events;

    ifstream file;
    file.open(argv[1]);

	translators = read_translators(file);
	events = read_events(file);

	events = translators_regulator(translators, events);

	print_result(events);
}


