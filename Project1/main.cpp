#include <iostream>

#include <SDL.h>

#include <SDL_image.h>

#include <SDL_ttf.h>

#include <string>

#include <vector>

#include <time.h>

SDL_Renderer * renderer;

using namespace std;
class WordsManager;
class GraphicManager;
class Hangman;
class Game;

class Hangman {
public: SDL_Texture * texture;
		SDL_Rect srect,
			drect;

		Hangman() {
			texture = IMG_LoadTexture(renderer, "assets/hangman2.png");
			srect.h = 400;
			srect.w = 200;
			srect.x = 0;
			srect.y = 0;

			drect.w = 200;
			drect.h = 400;
		};
		void update(int mistakes) {
			switch (mistakes) {
			case 0: {

				srect.x = 0;
				srect.y = 0;
				break;
			}
			case 1: {

				srect.x = 200;
				srect.y = 0;
				break;
			}
			case 2: {

				srect.x = 0;
				srect.y = 400;
				break;
			}
			case 3: {

				srect.x = 200;
				srect.y = 400;
				break;
			}
			case 4: {

				srect.x = 0;
				srect.y = 800;
				break;
			}
			case 5: {

				srect.x = 200;
				srect.y = 800;
				break;
			}
			}
		}
		void draw() {
			SDL_RenderCopy(renderer, texture, &srect, &drect);
		}
		void destroy() {
			texture = nullptr;
		}
};
class WordsManager {
private: vector < vector < string >> animals;
		 vector < vector < string >> food;
		 vector < vector < string >> countries;
		 vector < vector < string >> random;

public: WordsManager() {

	animals = {
	  {
		"bear",
		"lion",
		"frog",
		"duck",
		"dodo",
		"seal",
		"wolf",
		"deer",
		"crow",
		"hawk",
		"llama",
		"goat",
		"hare",
		"mole",
		"mule",
		"crab",
		"eel",
		"cow",
		"ox",
		"cat",
		"dog",
		"pika",
		"kiwi",
		"swan",
		"boar",
		"moth",
		"wasp",
		"puma",
		"dory",
		"dove",
		"toad",
		"tick",
		"flea",
		"worm",
		"tuna",
		"ibex",
		"lark",
		"hen",
		"ant",
		"fox",
		"bat",
		"ape",
		"pig",
		"bee",
		"cod",
		"gnu",
		"fly",
		"owl",
		"rat",
		"yak"
	  },
	  {
		"tiger",
		"zebra",
		"giraffe",
		"monkey",
		"donkey",
		"rabbit",
		"panda",
		"jaguar",
		"koala",
		"hyena",
		"lizard",
		"sheep",
		"otter",
		"ferret",
		"hippo",
		"koala",
		"rhino",
		"shark",
		"whale",
		"bison",
		"turtle",
		"horse",
		"mouse",
		"puppy",
		"polar",
		"moose",
		"falcon",
		"beagle",
		"lemur",
		"skunk",
		"eagle",
		"sloth",
		"cobra",
		"ferret",
		"squid",
		"camel",
		"shrew",
		"raven",
		"snail",
		"crane",
		"lemur",
		"Walrus",
		"chimp",
		"goose",
		"octopus",
		"pigeon",
		"baboon",
		"python",
		"beetle",
		"jaguar"
	  },
	  {
		"elephant",
		"alligator",
		"crocodile",
		"orangutan",
		"porpoise",
		"butterfly",
		"hummingbird",
		"woodchuck",
		"cheetah",
		"porcupine",
		"grasshopper",
		"anteater",
		"armadillo",
		"blackbear",
		"hedgehog",
		"chimpanzee",
		"jackrabbit",
		"kangaroo",
		"nightingale",
		"octopus",
		"peacock",
		"rattlesnake",
		"salamander",
		"tortoise",
		"whippoorwill",
		"bluewhale",
		"grizzlybear",
		"honeyeater",
		"antelope",
		"swordfish",
		"wallaby",
		"hippopotamus",
		"humpbackwhale",
		"raccoondog",
		"mountaingoat",
		"kingfisher",
		"hammerheadshark",
		"blackpanther",
		"orangutan",
		"siberiantiger",
		"bullmastiff",
		"mountainlion",
		"hummingbird",
		"butterfly",
		"bluebottlefly",
		"grasshopper",
		"spidermonkey",
		"hummingbird",
		"seahorse",
		"horseshoecrab"
	  }
	};
	food = {
	  {
		"apple",
		"bread",
		"broth",
		"candy",
		"chips",
		"cream",
		"crepe",
		"crisp",
		"curry",
		"donut",
		"fries",
		"grape",
		"gravy",
		"guava",
		"honey",
		"juice",
		"kebab",
		"mango",
		"maize",
		"melon",
		"olive",
		"oreos",
		"pasta",
		"peach",
		"pizza",
		"quark",
		"salsa",
		"salad",
		"steak",
		"sugar",
		"sushi",
		"toast",
		"wafer",
		"wings",
		"cake",
		"egg",
		"lamb",
		"plum",
		"kiwi",
		"tofu",
		"rice",
		"bun",
		"pie",
		"fig",
		"pea",
		"ham",
		"tea",
		"nut",
		"jam"
	  },
	  {
		"avocado",
		"burrito",
		"cookies",
		"popcorn",
		"spinach",
		"turnips",
		"coconut",
		"apricot",
		"muffin",
		"cereal",
		"tomato",
		"papaya",
		"muesli",
		"celery",
		"yogurt",
		"cheese",
		"pepper",
		"pickle",
		"walnut",
		"pudding",
		"banana",
		"orange",
		"squash",
		"almond",
		"sundae",
		"pistach",
		"raisin",
		"sorbet",
		"biryani",
		"pineapple",
		"broccoli",
		"artichoke",
		"eggplant",
		"tangerine",
		"pomegranate",
		"sausage",
		"hotdog",
		"baklava",
		"falafel",
		"hummus",
		"lentils",
		"custard",
		"brownie",
		"lasagna",
		"noodle",
		"pancake",
		"caramel",
		"biscuit",
		"brisket",
		"fritter"
	  },
	  {
		"spaghetti",
		"macaroni",
		"cauliflower",
		"fruitcake",
		"cranberries",
		"butterscotch",
		"marshmallow",
		"cantaloupe",
		"cheesecake",
		"candyapple",
		"jellybeans",
		"shishkebab",
		"dragonfruit",
		"gingerbread",
		"greenpepper",
		"maplesyrup",
		"miegoreng",
		"russetapple",
		"sweetpotato",
		"burdekinplum",
		"capulicherry",
		"custardapple",
		"indianjujube",
		"ladyfinger",
		"cottagecheese",
		"parmesancheese",
		"honeydewmelon",
		"butterchicken",
		"waterchestnut",
		"mashedpotatoes",
		"lemonade",
		"gingerale",
		"pinacolada",
		"pineapple",
		"pattypansquash",
		"brusselssprouts",
		"sandwiches",
		"potatocutlets",
		"springrolls",
		"chickencroquette",
		"boxpatties",
		"peanutbutter",
		"milkshake",
		"turkishdelight",
		"frenchfries",
		"tempurashrimp",
		"mintmargarita",
		"eggfriedrice",
		"manchurian",
		"nasigoreng"
	  }
	};
	countries = {
	  {
		"chad",
		"cuba",
		"fiji",
		"guam",
		"iran",
		"iraq",
		"laos",
		"mali",
		"niue",
		"oman",
		"peru",
		"togo",
		"aruba",
		"benin",
		"chile",
		"china",
		"egypt",
		"gabon",
		"ghana",
		"haiti",
		"india",
		"italy",
		"japan",
		"kenya",
		"libya",
		"macau",
		"malta",
		"nauru",
		"nepal",
		"niger",
		"palau",
		"qatar",
		"samoa",
		"spain",
		"sudan",
		"syria",
		"tonga",
		"yemen",
		"norway",
		"panama",
		"poland",
		"russia",
		"rwanda",
		"serbia",
		"sweden",
		"taiwan",
		"turkey",
		"tuvalu",
		"uganda",
		"zambia"
	  },
	  {
		"albania",
		"algeria",
		"pakistan",
		"armenia",
		"austria",
		"bahamas",
		"bahrain",
		"belarus",
		"belgium",
		"bermuda",
		"bolivia",
		"burundi",
		"comoros",
		"croatia",
		"curacao",
		"denmark",
		"argentina",
		"ecuador",
		"eritrea",
		"estonia",
		"finland",
		"georgia",
		"germany",
		"grenada",
		"hungary",
		"iceland",
		"ireland",
		"jamaica",
		"lebanon",
		"lesotho",
		"liberia",
		"mayotte",
		"moldova",
		"morocco",
		"myanmar",
		"namibia",
		"nigeria",
		"reunion",
		"romania",
		"senegal",
		"somalia",
		"tokelau",
		"tunisia",
		"ukraine"
		"uruguay",
		"vanuatu",
		"vietnam",
		"cambodia",
		"cameroon",
		"colombia"
	  },
	  {
		"argentina",
		"australia",
		"capeverde",
		"costarica",
		"gibraltar",
		"greenland",
		"guatemala",
		"indonesia",
		"isleofman",
		"lithuania",
		"mauritius",
		"nicaragua",
		"palestine",
		"sanmarino",
		"singapore",
		"venezuela",
		"azerbaijan",
		"bangladesh",
		"elsalvador",
		"guadeloupe",
		"ivorycoast",
		"kazakhstan",
		"kyrgyzstan",
		"luxembourg",
		"madagascar",
		"martinique",
		"mauritania",
		"micronesia",
		"montenegro",
		"montserrat",
		"mozambique",
		"newzealand",
		"northkorea",
		"puertorico",
		"saintlucia",
		"seychelles",
		"southkorea",
		"southsudan",
		"tajikistan",
		"timorleste",
		"uzbekistan",
		"sintmaarten",
		"southafrica",
		"switzerland",
		"vaticancity",
		"afghanistan",
		"netherlands",
		"philippines",
		"saudiarabia"
	  }
	};
	random = {
	  {
		"chad",
		"cuba",
		"fiji",
		"guam",
		"iran",
		"iraq",
		"laos",
		"mali",
		"niue",
		"oman",
		"peru",
		"togo",
		"aruba",
		"benin",
		"chile",
		"china",
		"egypt",
		"gabon",
		"ghana",
		"haiti",
		"india",
		"italy",
		"japan",
		"kenya",
		"libya",
		"macau",
		"malta",
		"nauru",
		"nepal",
		"niger",
		"palau",
		"qatar",
		"samoa",
		"spain",
		"sudan",
		"syria",
		"tonga",
		"yemen",
		"norway",
		"panama",
		"poland",
		"russia",
		"rwanda",
		"serbia",
		"sweden",
		"taiwan",
		"turkey",
		"tuvalu",
		"uganda",
		"zambia",
		"apple",
		"bread",
		"broth",
		"candy",
		"chips",
		"cream",
		"crepe",
		"crisp",
		"curry",
		"donut",
		"fries",
		"grape",
		"gravy",
		"guava",
		"honey",
		"juice",
		"kebab",
		"mango",
		"maize",
		"melon",
		"olive",
		"oreos",
		"pasta",
		"peach",
		"pizza",
		"quark",
		"salsa",
		"salad",
		"steak",
		"sugar",
		"sushi",
		"toast",
		"wafer",
		"wings",
		"cake",
		"egg",
		"lamb",
		"plum",
		"kiwi",
		"tofu",
		"rice",
		"bun",
		"pie",
		"fig",
		"pea",
		"ham",
		"tea",
		"nut",
		"jam",
		"bear",
		"lion",
		"frog",
		"duck",
		"dodo",
		"seal",
		"wolf",
		"deer",
		"crow",
		"hawk",
		"llama",
		"goat",
		"hare",
		"mole",
		"mule",
		"crab",
		"eel",
		"cow",
		"ox",
		"cat",
		"dog",
		"pika",
		"kiwi",
		"swan",
		"boar",
		"moth",
		"wasp",
		"puma",
		"dory",
		"dove",
		"toad",
		"tick",
		"flea",
		"worm",
		"tuna",
		"ibex",
		"lark",
		"hen",
		"ant",
		"fox",
		"bat",
		"ape",
		"pig",
		"bee",
		"cod",
		"gnu",
		"fly",
		"owl",
		"rat",
		"yak"
	  },
	  {
		"tiger",
		"zebra",
		"giraffe",
		"monkey",
		"donkey",
		"rabbit",
		"panda",
		"jaguar",
		"koala",
		"hyena",
		"lizard",
		"sheep",
		"otter",
		"ferret",
		"hippo",
		"koala",
		"rhino",
		"shark",
		"whale",
		"bison",
		"turtle",
		"horse",
		"mouse",
		"puppy",
		"polar",
		"moose",
		"falcon",
		"beagle",
		"lemur",
		"skunk",
		"eagle",
		"sloth",
		"cobra",
		"ferret",
		"squid",
		"camel",
		"shrew",
		"raven",
		"snail",
		"crane",
		"lemur",
		"Walrus",
		"chimp",
		"goose",
		"octopus",
		"pigeon",
		"baboon",
		"python",
		"beetle",
		"jaguar",
		"albania",
		"algeria",
		"pakistan",
		"armenia",
		"austria",
		"bahamas",
		"bahrain",
		"belarus",
		"belgium",
		"bermuda",
		"bolivia",
		"burundi",
		"comoros",
		"croatia",
		"curacao",
		"denmark",
		"argentina",
		"ecuador",
		"eritrea",
		"estonia",
		"finland",
		"georgia",
		"germany",
		"grenada",
		"hungary",
		"iceland",
		"ireland",
		"jamaica",
		"lebanon",
		"lesotho",
		"liberia",
		"mayotte",
		"moldova",
		"morocco",
		"myanmar",
		"namibia",
		"nigeria",
		"reunion",
		"romania",
		"senegal",
		"somalia",
		"tokelau",
		"tunisia",
		"ukraine",
		"uruguay",
		"vanuatu",
		"vietnam",
		"cambodia",
		"cameroon",
		"colombia",
		"avocado",
		"burrito",
		"cookies",
		"popcorn",
		"spinach",
		"turnips",
		"coconut",
		"apricot",
		"muffin",
		"cereal",
		"tomato",
		"papaya",
		"muesli",
		"celery",
		"yogurt",
		"cheese",
		"pepper",
		"pickle",
		"walnut",
		"pudding",
		"banana",
		"orange",
		"squash",
		"almond",
		"sundae",
		"pistach",
		"raisin",
		"sorbet",
		"biryani",
		"pineapple",
		"broccoli",
		"artichoke",
		"eggplant",
		"tangerine",
		"pomegranate",
		"sausage",
		"hotdog",
		"baklava",
		"falafel",
		"hummus",
		"lentils",
		"custard",
		"brownie",
		"lasagna",
		"noodle",
		"pancake",
		"caramel",
		"biscuit",
		"brisket",
		"fritter"
	  },
	  {
		"argentina",
		"australia",
		"capeverde",
		"costarica",
		"gibraltar",
		"greenland",
		"guatemala",
		"indonesia",
		"isleofman",
		"lithuania",
		"mauritius",
		"nicaragua",
		"palestine",
		"sanmarino",
		"singapore",
		"venezuela",
		"azerbaijan",
		"bangladesh",
		"elsalvador",
		"guadeloupe",
		"ivorycoast",
		"kazakhstan",
		"kyrgyzstan",
		"luxembourg",
		"madagascar",
		"martinique",
		"mauritania",
		"micronesia",
		"montenegro",
		"montserrat",
		"mozambique",
		"newzealand",
		"northkorea",
		"puertorico",
		"saintlucia",
		"seychelles",
		"southkorea",
		"southsudan",
		"tajikistan",
		"timorleste",
		"uzbekistan",
		"sintmaarten",
		"southafrica",
		"switzerland",
		"vaticancity",
		"afghanistan",
		"netherlands",
		"philippines",
		"saudiarabia",
		"spaghetti",
		"macaroni",
		"cauliflower",
		"fruitcake",
		"cranberries",
		"butterscotch",
		"marshmallow",
		"cantaloupe",
		"cheesecake",
		"candyapple",
		"jellybeans",
		"shishkebab",
		"dragonfruit",
		"gingerbread",
		"greenpepper",
		"maplesyrup",
		"miegoreng",
		"russetapple",
		"sweetpotato",
		"burdekinplum",
		"capulicherry",
		"custardapple",
		"indianjujube",
		"ladyfinger",
		"cottagecheese",
		"parmesancheese",
		"honeydewmelon",
		"butterchicken",
		"waterchestnut",
		"mashedpotatoes",
		"lemonade",
		"gingerale",
		"pinacolada",
		"pineapple",
		"pattypansquash",
		"brusselssprouts",
		"sandwiches",
		"potatocutlets",
		"springrolls",
		"chickencroquette",
		"boxpatties",
		"peanutbutter",
		"milkshake",
		"turkishdelight",
		"frenchfries",
		"tempurashrimp",
		"mintmargarita",
		"eggfriedrice",
		"manchurian",
		"nasigoreng",
		"elephant",
		"alligator",
		"crocodile",
		"orangutan",
		"porpoise",
		"butterfly",
		"hummingbird",
		"woodchuck",
		"cheetah",
		"porcupine",
		"grasshopper",
		"anteater",
		"armadillo",
		"blackbear",
		"hedgehog",
		"chimpanzee",
		"jackrabbit",
		"kangaroo",
		"nightingale",
		"octopus",
		"peacock",
		"rattlesnake",
		"salamander",
		"tortoise",
		"whippoorwill",
		"bluewhale",
		"grizzlybear",
		"honeyeater",
		"antelope",
		"swordfish",
		"wallaby",
		"hippopotamus",
		"humpbackwhale",
		"raccoondog",
		"mountaingoat",
		"kingfisher",
		"hammerheadshark",
		"blackpanther",
		"orangutan",
		"siberiantiger",
		"bullmastiff",
		"mountainlion",
		"hummingbird",
		"butterfly",
		"bluebottlefly",
		"grasshopper",
		"spidermonkey",
		"hummingbird",
		"seahorse",
		"horseshoecrab"
	  }
	};
}
		int rnd_index(int i) {
			srand(time(NULL) << 5);

			return rand() % i;
		}
		string returnWord(int diff, string Category) {
			if (Category == "animals")
				return animals[diff][rnd_index(animals[diff].size())];
			else if (Category == "food")
				return food[diff][rnd_index(food[diff].size())];
			else if (Category == "countries")
				return countries[diff][rnd_index(countries[diff].size())];
			else if (Category == "random")
				return random[diff][rnd_index(random[diff].size())];
			else
				return " ";
		}
		string returnWord() {
			return random[0][rnd_index(random[0].size())];
		}
};
class Mouse {
public: SDL_Rect rect;
		SDL_Rect point;
		Mouse() {
			rect.w = 25;
			rect.h = 25;

			point.w = 1;
			point.h = 1;
		}
		void update() {
			SDL_GetMouseState(&rect.x, &rect.y);
			point.x = rect.x;
			point.y = rect.y;
		}
};
class Button {
public: SDL_Texture * texture;
		SDL_Rect srect,
			drect;
		bool isSelected = false;

		Button() {
			texture = IMG_LoadTexture(renderer, "assets/buttons.png");
			srect.h = 100;
			srect.w = 400;
			srect.x = 0;

			drect.w = 200;
			drect.h = 50;
		};

		void update(Mouse & mouse) {
			if (SDL_HasIntersection(&drect, &mouse.point)) {
				isSelected = true;
				srect.x = 400;
			}
			else {
				isSelected = false;
				srect.x = 0;
			}
		}
		void clicked() {
			drect.w = 210;
			drect.h = 60;

			drect.x -= 5;
			drect.y -= 5;
		}
		void released() {
			SDL_RenderClear(renderer);
			drect.w = 200;
			drect.h = 50;

			drect.x += 5;
			drect.y += 5;
		}
		void draw() {
			SDL_RenderCopy(renderer, texture, &srect, &drect);
		}
		void destroy() {
			texture = nullptr;
		}
};
class Game {
protected: WordsManager wordsHouse;
		   int mistakesCount;
		   string mistakes;
		   int guessedCount;
		   string guessed;
		   int wordLength;
		   string word;
		   int difficulty;
		   string category;

public: Game() {
	mistakesCount = 0;
	guessedCount = 0;
}
		virtual string getWord() = 0;
		int getMistakesCount() {
			return mistakesCount;
		}
		string getGuessed() {
			return guessed;
		};
		string getMistakes() {
			return mistakes;
		};
		bool checkChar(char ch, string & errMessage) {
			bool flag = false;
			if (mistakes.find(ch) != string::npos || guessed.find(ch) != string::npos) {
				errMessage = "Already entered before";
				return flag;
			}
			else {
				for (int i = 0; i < wordLength; ++i) {
					if (word[i] == ch) {
						guessed[i] = word[i];

						errMessage = "Correct!";
						flag = true;
					}
				}
			}
			if (!flag) {
				++mistakesCount;
				errMessage = "Wrong";
				mistakes += ch;
			}
			else {
				++guessedCount;
			}
			return flag;
		}
		string getCorrectWord() {
			return word;
		}

		void setDifficulty(int difficulty) {
			this->difficulty = difficulty;
		}
		void setCategory(string category) {
			this->category = category;
		}
};
class Classic : public Game {
public: string getWord() override {
	word = wordsHouse.returnWord(difficulty, category);
	for (int i = 0; i < word.length(); ++i) {
		guessed += "_";
	}
	mistakes = "";
	mistakesCount = 0;
	guessedCount = 0;
	wordLength = word.length();
	return guessed;
}
};
class TimeTrial : public Game {
public: int timer;
		Uint32 startTime;
		Uint32 currentTime;
		Uint32 elapsedTime;

public: TimeTrial() {
	timer = 59;
	startTime = SDL_GetTicks();
	currentTime = 0;
	elapsedTime = currentTime - startTime;

};
		int gettimer() {
			return timer;
		}
		void setcurrentTime(int x) {
			currentTime = x;
		}
		Uint32 getelapsedTime() {
			return elapsedTime;
		}
		Uint32 getstartTime() {
			return startTime;
		}
		string getWord() override {
			word = wordsHouse.returnWord();
			guessed = "";
			for (int i = 0; i < word.length(); ++i) {
				guessed += "_";
			}
			mistakes = "";
			mistakesCount = 0;
			guessedCount = 0;
			wordLength = word.length();
			return guessed;
		}
};
class Text {
public: string fontPath;
		int fontSize;
		int space;
		string message;
		SDL_Color * color;
		SDL_Surface * charSurface;
		SDL_Texture * charTexture;
		SDL_Rect charRect;
		TTF_Font * font;

public: Text(string fontPath, int fontSize, string message, SDL_Color color) {
	this->fontPath = fontPath;
	this->fontSize = fontSize;
	this->message = message;
	this->color = &color;
	font = TTF_OpenFont(fontPath.c_str(), fontSize);
	if (!font)
		cout << endl <<
		"Failed to load font" << message << endl;
}
		void setMessage(string message) {
			this->message = message;
		}
		void draw(int posx, int posy, int space) {
			this->space = space;
			for (int i = 0; message[i] != '\0'; ++i) {
				// Render each character
				charSurface = TTF_RenderGlyph_Solid(font, message[i], *color);
				if (!charSurface)
					cout << endl <<
					"Surface failure" << message << endl;
				charTexture = SDL_CreateTextureFromSurface(renderer, charSurface);
				if (!charTexture)
					cout << endl <<
					"Texture failure" << message << endl;
				// Set character position (adjust x for spacing)

				charRect.x = posx;
				charRect.y = posy;
				charRect.w = charSurface->w;
				charRect.h = charSurface->h;

				// Render character
				SDL_RenderCopy(renderer, charTexture, nullptr, &charRect);
				SDL_RenderPresent(renderer);
				// Update x-coordinate for next character
				posx += charRect.w + space; // Adjust desiredSpacing as needed

				//}

				// Render character
				//SDL_RenderCopy(renderer, charTexture, nullptr, &charRect);
			}
		}

		void draw(int posx, int posy) {
			const char * text = message.c_str();
			charSurface = TTF_RenderText_Solid(font, message.c_str(), *color);
			if (!charSurface)
				cout << endl <<
				"Surface failure" << message << endl;
			charTexture = SDL_CreateTextureFromSurface(renderer, charSurface);
			if (!charTexture)
				cout << endl <<
				"Texture failure" << message << endl;
			charRect.x = posx;
			charRect.y = posy;
			charRect.w = charSurface->w;
			charRect.h = charSurface->h;
			SDL_RenderCopy(renderer, charTexture, nullptr, &charRect);
			SDL_RenderPresent(renderer);
		}

		void destroy() {
			SDL_FreeSurface(charSurface);
			SDL_DestroyTexture(charTexture);
		}
};
class GraphicManager {
public: SDL_Window * window;
		Game * game;
		SDL_DisplayMode dm;
		SDL_Event event;
		SDL_Surface * background;
		SDL_Texture * imageTexture;
		SDL_Rect textureDestination;
		Mouse cursor;
		SDL_Color textColor;
		int windowWidth;
		int windowHeight;

public: GraphicManager() {
	start();
};
		bool start() {
			try {
				if (SDL_Init(SDL_INIT_VIDEO) < 0) {
					throw 404;
				}
				if (TTF_Init() == -1) {
					throw 'f';
				}
				if (!IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG || !IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) {
					throw "img";
				}

			}
			catch (int a) {
				cout << "Sdl not initialized" << SDL_GetError();
				return false;

			}
			catch (char ch) {
				cout << endl <<
					"sdl ttf  not initialized" << SDL_GetError();
				return false;
			}
			catch (string str) {
				cout << "Sdl img not initialized" << SDL_GetError();
				return false;
			}

			// to open a centered window
			SDL_GetCurrentDisplayMode(0, &dm);
			int screenWidth = dm.w;
			int screenHeight = dm.h;
			windowWidth = 960;
			windowHeight = 540;
			int posX = (screenWidth - windowWidth) / 2;
			int posY = (screenHeight - windowHeight) / 2;
			window = SDL_CreateWindow("Hangman Redefined", posX, posY, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
			renderer = SDL_CreateRenderer(window, -1, 0);

			// background image
			background = IMG_Load("assets/loader.jpg");
			imageTexture = SDL_CreateTextureFromSurface(renderer, background);
			//	SDL_FreeSurface(background);
			textureDestination.x = 0;
			textureDestination.y = 0;
			textureDestination.w = windowWidth;
			textureDestination.h = windowHeight;
			SDL_RenderCopy(renderer, imageTexture, nullptr, &textureDestination);

			Button startButton;
			startButton.srect.y = 0;
			startButton.drect.x = 500;
			startButton.drect.y = 350;
			Button exitButton;
			exitButton.srect.y = 100;
			exitButton.drect.x = 710;
			exitButton.drect.y = 350;
			bool isRunning = true;
			while (isRunning) {
				cursor.update();
				startButton.update(cursor);
				exitButton.update(cursor);
				while (SDL_PollEvent(&event) != 0) {
					if (event.type == SDL_QUIT) {
						isRunning = false;
						quitMethods();
					};
					if (SDL_HasIntersection(&startButton.drect, &cursor.point)) {
						if (event.type == SDL_MOUSEBUTTONDOWN) {
							startButton.clicked();
						}
						if (event.type == SDL_MOUSEBUTTONUP) {
							startButton.released();
							startButton.texture = nullptr;
							exitButton.texture = nullptr;
							displayMenu();
						}
					}
					if (SDL_HasIntersection(&exitButton.drect, &cursor.point)) {
						if (event.type == SDL_MOUSEBUTTONDOWN) {
							exitButton.clicked();
						}
						if (event.type == SDL_MOUSEBUTTONUP) {
							exitButton.released();
							SDL_Delay(200);
							isRunning = false;
							quitMethods();
						}
					}
				}
				startButton.draw();
				exitButton.draw();
				SDL_RenderPresent(renderer);
			}

			return true;
		};
		void displayMenu() {
			background = IMG_Load("assets/menuback.jpg");
			imageTexture = SDL_CreateTextureFromSurface(renderer, background);
			SDL_RenderCopy(renderer, imageTexture, nullptr, &textureDestination);
			SDL_RenderPresent(renderer);
			Button classicButton;
			classicButton.srect.y = 200;
			classicButton.drect.x = 400;
			classicButton.drect.y = 200;
			Button timeButton;
			timeButton.srect.y = 400;
			timeButton.drect.x = 400;
			timeButton.drect.y = 260;
			string fontName = "assets/Anton.ttf";
			bool isRunning = true;
			while (isRunning) {
				cursor.update();
				classicButton.update(cursor);
				timeButton.update(cursor);
				while (SDL_PollEvent(&event) != 0) {
					if (event.type == SDL_QUIT) {
						isRunning = false;
					}
					if (SDL_HasIntersection(&classicButton.drect, &cursor.point)) {
						if (event.type == SDL_MOUSEBUTTONDOWN) {
							classicButton.clicked();
						}
						if (event.type == SDL_MOUSEBUTTONUP) {
							classicButton.released();
							classicButton.destroy();
							timeButton.destroy();

							// game object classic game reference passed
							Classic classicGame;
							game = &classicGame;

							Button basicButton;
							basicButton.srect.y = 800;
							basicButton.drect.x = 400;
							basicButton.drect.y = 150;
							Button intermediateButton;
							intermediateButton.srect.y = 300;
							intermediateButton.drect.x = 400;
							intermediateButton.drect.y = 200;
							Button ExpertButton;
							ExpertButton.srect.y = 500;
							ExpertButton.drect.x = 400;
							ExpertButton.drect.y = 250;
							bool flag = true;
							while (flag) {
								cursor.update();
								basicButton.update(cursor);
								intermediateButton.update(cursor);
								ExpertButton.update(cursor);
								SDL_RenderClear(renderer);
								SDL_RenderCopy(renderer, imageTexture, nullptr, &textureDestination);
								basicButton.draw();
								intermediateButton.draw();
								ExpertButton.draw();
								SDL_RenderPresent(renderer);
								while (SDL_PollEvent(&event) != 0) {
									if (event.type == SDL_QUIT) {
										flag = false;
									}
									if (SDL_HasIntersection(&basicButton.drect, &cursor.point)) {
										if (event.type == SDL_MOUSEBUTTONDOWN) {
											basicButton.clicked();
										}
										if (event.type == SDL_MOUSEBUTTONUP) {
											basicButton.released();
											basicButton.destroy();
											intermediateButton.destroy();
											ExpertButton.destroy();
											startGame(0);
										}
									}
									if (SDL_HasIntersection(&intermediateButton.drect, &cursor.point)) {
										if (event.type == SDL_MOUSEBUTTONDOWN) {
											intermediateButton.clicked();
										}
										if (event.type == SDL_MOUSEBUTTONUP) {
											intermediateButton.released();

											basicButton.destroy();
											intermediateButton.destroy();
											ExpertButton.destroy();
											startGame(1);
										}
									}
									if (SDL_HasIntersection(&ExpertButton.drect, &cursor.point)) {
										if (event.type == SDL_MOUSEBUTTONDOWN) {
											ExpertButton.clicked();
										}
										if (event.type == SDL_MOUSEBUTTONUP) {
											ExpertButton.released();
											basicButton.destroy();
											intermediateButton.destroy();
											ExpertButton.destroy();
											startGame(2);
										}
									}
								}

							}
						}
					}
					if (SDL_HasIntersection(&timeButton.drect, &cursor.point)) {
						if (event.type == SDL_MOUSEBUTTONDOWN) {
							timeButton.clicked();
						}
						if (event.type == SDL_MOUSEBUTTONUP) {
							timeButton.released();
							timeButton.destroy();
							classicButton.destroy();
							TimeTrial timeMode;
							game = &timeMode;
							string ins1 = "welcome to Time Trial mode... ";
							string ins2 = "You will be given 60 seconds, score as much as you can...";
							Text instructions1(fontName, 30, ins1, {
							  240,
							  250,
							  100,
							  255
								});
							Text instructions2(fontName, 30, ins2, {
							  240,
							  250,
							  100,
							  255
								});
							SDL_RenderCopy(renderer, imageTexture, nullptr, &textureDestination);

							instructions1.draw(100, 200, 2);
							instructions2.draw(100, 250, 2);
							SDL_Delay(5000);
							instructions1.destroy();
							instructions2.destroy();
							startGame();
						}
					}
				}
				SDL_RenderCopy(renderer, imageTexture, nullptr, &textureDestination);
				classicButton.draw();
				timeButton.draw();
				SDL_RenderPresent(renderer);
			}
		}
		void startGame(int choice) {
			//SDL_RenderClear(renderer);

			Button animalButton;
			animalButton.srect.y = 600;
			animalButton.drect.x = 400;
			animalButton.drect.y = 100;
			Button coutriesButton;
			coutriesButton.srect.y = 700;
			coutriesButton.drect.x = 400;
			coutriesButton.drect.y = 160;
			Button foodButton;
			foodButton.srect.y = 900;
			foodButton.drect.x = 400;
			foodButton.drect.y = 220;
			Button randomButton;
			randomButton.srect.y = 1000;
			randomButton.drect.x = 400;
			randomButton.drect.y = 280;
			bool isRunning = true;
			while (isRunning) {
				cursor.update();
				animalButton.update(cursor);
				coutriesButton.update(cursor);
				foodButton.update(cursor);
				randomButton.update(cursor);
				SDL_RenderClear(renderer);
				SDL_RenderCopy(renderer, imageTexture, nullptr, &textureDestination);
				animalButton.draw();
				coutriesButton.draw();
				foodButton.draw();
				randomButton.draw();
				SDL_RenderPresent(renderer);
				while (SDL_PollEvent(&event) != 0) {
					if (event.type == SDL_QUIT) {
						isRunning = false;
					}
					if (SDL_HasIntersection(&animalButton.drect, &cursor.point)) {
						if (event.type == SDL_MOUSEBUTTONDOWN) {
							animalButton.clicked();
						}
						if (event.type == SDL_MOUSEBUTTONUP) {
							animalButton.released();
							animalButton.destroy();
							coutriesButton.destroy();
							foodButton.destroy();
							randomButton.destroy();
							classicGame(choice, "animals");
						}
					}
					if (SDL_HasIntersection(&coutriesButton.drect, &cursor.point)) {
						if (event.type == SDL_MOUSEBUTTONDOWN) {
							coutriesButton.clicked();
						}
						if (event.type == SDL_MOUSEBUTTONUP) {
							coutriesButton.released();
							animalButton.destroy();
							coutriesButton.destroy();
							foodButton.destroy();
							randomButton.destroy();
							classicGame(choice, "countries");
						}
					}
					if (SDL_HasIntersection(&foodButton.drect, &cursor.point)) {
						if (event.type == SDL_MOUSEBUTTONDOWN) {
							foodButton.clicked();
						}
						if (event.type == SDL_MOUSEBUTTONUP) {
							foodButton.released();
							animalButton.destroy();
							coutriesButton.destroy();
							foodButton.destroy();
							randomButton.destroy();
							classicGame(choice, "food");
						}
					}
					if (SDL_HasIntersection(&randomButton.drect, &cursor.point)) {
						if (event.type == SDL_MOUSEBUTTONDOWN) {
							randomButton.clicked();
						}
						if (event.type == SDL_MOUSEBUTTONUP) {
							randomButton.released();
							animalButton.destroy();
							coutriesButton.destroy();
							foodButton.destroy();
							randomButton.destroy();
							classicGame(choice, "random");
						}
					}
				}

			}
		}
		void classicGame(int difficulty, string category) {
			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer, imageTexture, nullptr, &textureDestination);
			SDL_RenderPresent(renderer);
			game->setCategory(category);
			game->setDifficulty(difficulty);
			//hangman spirit
			Hangman hangman;
			hangman.drect.x = 760;
			hangman.drect.y = 100;
			hangman.update(game->getMistakesCount());
			hangman.draw();

			//get random word, guessed dashes wala return hoga yaha
			string fontName = "assets/Anton.ttf";
			string guessed = game->getWord();
			int textPosX = 150;
			int textPosY = 200;
			textColor = {
			  0,
			  0,
			  0,
			  0
			};
			Text * wordToDisplay = new Text(fontName, 30, guessed, textColor);
			wordToDisplay->draw(textPosX, textPosY, 20);
			Text displayMistakes(fontName, 30, game->getMistakes(), {
			  255,
			  0,
			  0,
			  255
				});
			Text enteredChar(fontName, 10, " ", textColor);
			displayMistakes.draw(250, 50, 10);
			//mistakes head
			string mistakeHeadStr = "M i s t a k e s : ";
			Text mistakesHead(fontName, 30, mistakeHeadStr, textColor);
			mistakesHead.draw(50, 10);
			bool isRunning = true;
			while (isRunning && game->getMistakesCount() < 5) {
				cursor.update();
				while (SDL_PollEvent(&event) && game->getMistakesCount() < 5) {
					SDL_RenderClear(renderer);
					SDL_RenderCopy(renderer, imageTexture, nullptr, &textureDestination);
					hangman.draw();
					displayMistakes.setMessage(game->getMistakes());
					displayMistakes.draw(100, 50, 10);
					wordToDisplay->draw(textPosX, textPosY, 20);
					mistakesHead.draw(50, 10);
					SDL_RenderPresent(renderer);
					switch (event.type) {
					case SDL_QUIT:
						isRunning = false;
						quitMethods();
						break;
					case SDL_KEYUP:
						if (event.key.keysym.sym >= SDLK_a && event.key.keysym.sym <= SDLK_z) {
							string userInput;
							string error;
							char key = static_cast <char> (event.key.keysym.sym);
							userInput.push_back(key);
							userInput += " :";
							Text userText(fontName, 30, userInput, textColor);
							Text displayError(fontName, 30, error, textColor);
							userText.draw(50, 400, 0);
							cout << "Key Pressed: " << key << '\n';
							if (game->checkChar(key, error)) {
								delete wordToDisplay;
								guessed = game->getGuessed();
								wordToDisplay = new Text(fontName, 30, guessed, textColor);
								//message like correct or not
								displayError.setMessage(error);
								displayError.draw(100, 400);

								//display mistakes

							}
							else {
								displayMistakes.setMessage(game->getMistakes());
								hangman.update(game->getMistakesCount());
								displayMistakes.draw(100, 50, 10);
								displayError.setMessage(error);
								displayError.draw(100, 400, 0);

							}
							displayError.destroy();
							userText.destroy();
						}
						break;
					default:
						break;
					}
					hangman.draw();
					SDL_RenderPresent(renderer);
					if (guessed.find('_') == string::npos) {
						isRunning = false;
						continue;
					}
				}
			}

			//RESULT TO BE SHOWN BELOW
			string res;
			if (game->getMistakesCount() >= 5) {
				res = "You Lose, Try Next Time";
			}
			else {
				res = "Congratulations, You Won";
			}
			Text Result(fontName, 30, res, textColor);
			Result.draw(50, 300, 0);
			hangman.drect.x -= 20;
			hangman.drect.y -= 20;
			hangman.drect.w += 40;
			hangman.drect.h += 40;
			hangman.draw();
			Button exitButton;
			exitButton.srect.y = 100;
			exitButton.drect.x = 200;
			exitButton.drect.y = 350;
			isRunning = true;
			string Word = game->getCorrectWord();
			delete wordToDisplay;
			wordToDisplay = new Text(fontName, 30, Word, textColor);
			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer, imageTexture, nullptr, &textureDestination);
			wordToDisplay->draw(textPosX, textPosY, 10);
			hangman.draw();
			cursor.update();
			exitButton.update(cursor);
			exitButton.draw();
			Result.draw(50, 300);
			SDL_RenderPresent(renderer);
			while (isRunning) {
				cursor.update();
				exitButton.update(cursor);
				exitButton.draw();
				SDL_RenderPresent(renderer);
				SDL_Event ev;
				while (SDL_PollEvent(&ev) != 0 && isRunning) {
					if (ev.type == SDL_QUIT) {
						isRunning = false;
						hangman.destroy();
						exitButton.destroy();
						Result.destroy();
						delete wordToDisplay;

						quitMethods();
						continue;
					};
					if (SDL_HasIntersection(&exitButton.drect, &cursor.point)) {
						if (ev.type == SDL_MOUSEBUTTONDOWN) {
							exitButton.clicked();
						}
						if (ev.type == SDL_MOUSEBUTTONUP) {
							exitButton.released();
							SDL_Delay(200);
							isRunning = false;
							hangman.destroy();
							exitButton.destroy();
							Result.destroy();
							delete wordToDisplay;
							quitMethods();
							//continue;
						}
					}
				}

			}
		}
		void startGame() {
			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer, imageTexture, nullptr, &textureDestination);
			string fontName = "assets/Anton.ttf";
			textColor = {
			  0,
			  0,
			  0,
			  255
			};
			Hangman hangman;
			hangman.drect.x = 760;
			hangman.drect.y = 100;
			hangman.update(0);
			hangman.draw();
			TimeTrial CountDown;
			int score = 0;
			string scoreStr = to_string(score);
			string timeStr = to_string(CountDown.timer);
			string remainTimeStr = "Remaining Time: ";
			Text timeHead(fontName, 20, remainTimeStr, textColor);
			string scoreHeadStr = "Score: ";
			Text scoreHead(fontName, 20, scoreHeadStr, textColor);
			Text timeDisplay(fontName, 40, timeStr, textColor);
			Text scoreDisplay(fontName, 20, scoreStr, textColor);
			scoreDisplay.draw(windowWidth - 250, 200);
			int textPosX = 150;
			int textPosY = 200;
			while (CountDown.gettimer() >= 0) { ///EXTREME OUTER LOOP

			  //from classic game function
				string guessed = game->getWord();
				Text * wordToDisplay = new Text(fontName, 30, guessed, textColor);
				Text enteredChar(fontName, 10, " ", textColor);
				Text displayMistakes(fontName, 30, game->getMistakes(), textColor);
				string mistakeHeadStr = "M i s t a k e s : ";
				Text mistakesHead(fontName, 30, mistakeHeadStr, textColor);
				//wordToDisplay->draw(textPosX, textPosY, 20);
				//displayMistakes.draw(250, 50, 10);
				//mistakes head
				mistakesHead.draw(50, 10, 0);
				SDL_Event e;
				bool isRunning = true;
				SDL_RenderClear(renderer);
				scoreDisplay.draw(windowWidth - 250, 200);
				scoreDisplay.charTexture = nullptr;
				scoreStr = to_string(score);
				scoreDisplay.setMessage(scoreStr);
				SDL_RenderClear(renderer);
				SDL_RenderCopy(renderer, imageTexture, nullptr, &textureDestination);
				scoreDisplay.draw(windowWidth - 250, 200);
				timeStr = to_string(CountDown.timer);
				timeDisplay.setMessage(timeStr);
				timeDisplay.draw(windowWidth - 200, 100);
				timeHead.draw(windowWidth - 400, 100);
				scoreHead.draw(windowWidth - 300, 200);
				hangman.update(game->getMistakesCount());
				hangman.draw();
				displayMistakes.setMessage(game->getMistakes());
				displayMistakes.draw(100, 50, 10);
				wordToDisplay->draw(textPosX, textPosY, 20);
				mistakesHead.draw(50, 10);
				SDL_RenderPresent(renderer);
				while (isRunning && CountDown.gettimer() >= 0) {
					cursor.update();
					timeDisplay.charTexture = nullptr;
					timeStr = to_string(CountDown.timer);
					SDL_RenderClear(renderer);
					SDL_RenderCopy(renderer, imageTexture, nullptr, &textureDestination);
					hangman.draw();
					mistakesHead.draw(50, 10);
					scoreHead.draw(windowWidth - 300, 200);
					timeHead.draw(windowWidth - 400, 100);
					scoreDisplay.draw(windowWidth - 250, 200);
					//timeDisplay.setMessage(timeStr);
					timeDisplay.draw(windowWidth - 200, 100);
					displayMistakes.setMessage(game->getMistakes());
					displayMistakes.draw(100, 50, 10);
					wordToDisplay->draw(textPosX, textPosY, 20);
					SDL_RenderPresent(renderer);

					while (SDL_PollEvent(&event) && CountDown.gettimer() >= 0) {

						switch (event.type) {
						case SDL_QUIT:
							isRunning = false;
							quitMethods();
							break;
						case SDL_KEYUP:
							if (event.key.keysym.sym >= SDLK_a && event.key.keysym.sym <= SDLK_z) {
								string userInput;
								string error;
								char key = static_cast <char> (event.key.keysym.sym);
								userInput.push_back(key);
								userInput += " :";
								Text userText(fontName, 20, userInput, textColor);

								Text displayError(fontName, 30, error, textColor);
								userText.draw(50, 400);
								cout << "Key Pressed: " << key << '\n';
								if (game->checkChar(key, error)) {
									delete wordToDisplay;
									guessed = game->getGuessed();
									wordToDisplay = new Text(fontName, 30, guessed, textColor);
									//						wordToDisplay->draw(textPosX, textPosY,20);
									//message like correct or not
									displayError.setMessage(error);
									displayError.draw(100, 400, 0);
									SDL_Delay(400);
									//display mistakes
								}
								else {
									displayMistakes.setMessage(game->getMistakes());
									hangman.update(game->getMistakesCount());
									hangman.draw();
									//displayMistakes.draw(100, 50, 0);
									displayError.setMessage(error);
									displayError.draw(100, 400, 0);
									SDL_Delay(400);
								}
							}
							break;
						default:
							break;
						}

						if (guessed.find('_') == string::npos) {
							score += 10;
							wordToDisplay->destroy();
							isRunning = false;
							continue;
						}
						if (game->getMistakesCount() >= 5) {
							isRunning = false;
							wordToDisplay->destroy();
							score -= 5;
							continue;
						}
					}
					// Update timer
					CountDown.setcurrentTime(SDL_GetTicks());
					CountDown.elapsedTime = CountDown.currentTime - CountDown.startTime;
					if (CountDown.elapsedTime >= 1000) {
						CountDown.timer--;
						CountDown.startTime = CountDown.currentTime;

						timeStr = to_string(CountDown.timer);
						timeDisplay.setMessage(timeStr);
						//timeDisplay.draw(windowWidth - 200, 100);
					}

				}
			}

			//RESULT TO BE SHOWN BELOW
			Button exitButton;
			exitButton.srect.y = 100;
			exitButton.drect.x = 200;
			exitButton.drect.y = 350;
			scoreStr = to_string(score);
			scoreDisplay.setMessage(scoreStr);

			bool isRunning = true;
			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer, imageTexture, nullptr, &textureDestination);
			scoreHead.draw(windowWidth / 2 - 100, 200);
			scoreDisplay.draw(windowWidth / 2 - 50, 200);
			cursor.update();
			exitButton.update(cursor);
			exitButton.draw();
			SDL_RenderPresent(renderer);
			while (isRunning) {
				cursor.update();
				exitButton.update(cursor);
				exitButton.draw();
				SDL_RenderPresent(renderer);
				SDL_Event ev;
				while (SDL_PollEvent(&ev) != 0 && isRunning) {
					if (ev.type == SDL_QUIT) {
						isRunning = false;
						hangman.destroy();
						exitButton.destroy();
						quitMethods();
						continue;
					};
					if (SDL_HasIntersection(&exitButton.drect, &cursor.point)) {
						if (ev.type == SDL_MOUSEBUTTONDOWN) {
							exitButton.clicked();
						}
						if (ev.type == SDL_MOUSEBUTTONUP) {
							exitButton.released();
							//SDL_Delay(200);
							isRunning = false;
							exitButton.destroy();
							quitMethods();
						}
					}
				}

			}
		};
		bool quitMethods() {
			cout << "quitmethods called" << endl;
			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(window);
			SDL_DestroyTexture(imageTexture);
			IMG_Quit();
			TTF_Quit();
			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(window);
			SDL_Quit();
			return false;
		}
		~GraphicManager() {
			cout << "Destructor called" << endl;
			IMG_Quit();
			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(window);
			SDL_Quit();
		}
};

int main(int argc, char * argv[]) {
	GraphicManager g;

	return 0;
}