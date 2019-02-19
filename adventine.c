#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "adventine_header.h"

/* --------------------------------------- */

/* Declare variables */
	
/** GAME VARIABLES **/
char name[200];
int room = 1;
char door_status[10] = "closed";
/** MOBS **/
int zombie = 1;
int skeleton = 1;

/** BACKPACK ITEMS (use boolean-style) **/
char letter[4] = "no";
char candle[4] = "no"; /*** to use: 'candle=yes;' DEFAULT: 'candle=no;' ***/
char book[4] = "no";
char sword[4] = "no";
char amulet[4] = "no";
char moss[4] = "no";
char key[4] = "no";
char bones[4] = "no";
char rope[4] = "no";
char ring[4] = "no";


/* STATUSES */

int ring_equip = 0; /* 1 for equipped or 0 for no */
int amulet_equip = 0;/* ^same */

int spell_light 0;

int light = 0;
/* ----------------------------------------- */

/** Side Functions **/

void close(void);
{
	puts("\nEnter a command> ");
}

void seedrnd(void)
{
	srand((unsigned)time(NULL));
}

int rnd_10(int range)
{
	int r;

	r=rand()%range+1;

	return(r);
}
/***----------------------------- START ACTION FUNCTIONS -------------------------------***/

void act_take(void)
{
	char p_valid[]="\nWhat would you like to take?: ";
	char p_invalid[]="\nThere is nothing to take... ";

	char temp_input[20];

	switch(room)
	{
		case 1:
		{
			puts("%c",p_valid);
			gets(temp_input);
			if(temp_input == "candle")
			{	
				puts("\n\"Candle Added to Backpack\"");
				close();
				candle="yes";
			}
			else
			{
				puts("\nThat is not here... ");
				close();
				break;
			}
			break;
		}/* end case 1 */
		case 2:
		{
			puts("%c",p_valid);
			gets(temp_input);
			if(temp_input == "letter")
			{
				puts("\n\"Letter Added to Backpack\"");
				close();
				letter="yes";
			}
			else
			{
				puts("\nThat is not here... ");
				close();
				break;
			}
			break;
		}/* end case 2 */
		case 3:
		{
			puts("%c",p_valid);
			gets(temp_input);
			if(temp_input == "book")
			{
				puts("\n\"Book Added to Backpack\"");
				close();
				book="yes";
			}
			else
			{
				puts("\nThat is not here... ");
				close();
				break;
			}
			break; /* put this at end for each case */
		}/* end case 3 */
		case 4:
		{
			puts("%c",p_valid);
			gets(temp_input);
			if(temp_input == "sword")
			{
				puts("\n\"Sword Added to Backpack\"");
				close();
				sword="yes";
			}
			else
			{
				puts("\nThat is not here... ");
				close();
				break;
			}
			break;
		}/* end case 4 */
		case 5:
		{
			puts("%c",p_valid);
			gets(temp_input);
			if(temp_input == "amulet")
			{
				puts("\n\"Amulet Added to Backpack\"");
				close();
				amulet="yes";
			}
			else
			{
				puts("\nThat is not here... ");
				close();
				break;
			}
			break;
		}/* end case 5 */
		case 6:
		{
			puts("%c",p_valid);
			gets(temp_input);
			if(temp_input == "moss")
			{
				puts("\n\"Moss Added to BackPack\"");
				close();
				amulet="yes";
			}
			else
			{
				puts("\nThat is not here... ");
				close();
				break;
			}
			break;
		}/* end case 6 */
		case 7:
		{
			puts("%c",p_invalid);
			close();
			break;
		}/* end case 7 */
		case 8:
		{
			puts("%c",p_valid);
			gets(temp_input);
			if(temp_input == "key")
			{
				puts("\n\"Key Added to Backpack\"");
				close();
				key="yes";
			}
			else
			{
				puts("\nThat is not here... ");
				close();
				break;
			}
			break;
		}/* end case 8 */
		case 9:
		{
			puts("%c",p_valid);
			gets(temp_input);
			if(temp_input == "bones")
			{
				puts("\n\"Bones Added to Backpack\"");
				close();
				bones="yes";
			}
			else
			{
				puts("\nThat is not here... ");
				close();
				break;
			}
			break;
		}/* end case 9 */
		case 10:
		{
			puts("%c",p_valid);
			gets(temp_input);
			if(temp_input == "rope")
			{
				puts("\n\"Rope Added to Backpack\"");
				close();
				rope="yes";
			}
			else
			{
				puts("\nThat is not here... ");
				close();
				break;
			}
			break;
		}/* end case 10 */
		case 11:
		{
			puts("%c",p_invalid);
			close();
			break;
		}/* end case 11 */
		case 12:
		{
			puts("%c",p_valid);
			gets(temp_input);
			if(temp_input == "ring")
			{
				puts("\n\"Ring Added to Backpack\"");
				close();
				ring="yes";
			}
			else
			{
				puts("\nThat is not here... ");
				close();
				break;
			}
			break;
		}/* end case 12 */
		default:
		{
			puts("%c",p_invalid);
			close();
			break;
		}/* end case 'default' */
		


		
	}/* for 'switch' */
}/* end 'act_take' */


void act_read(void)
{
	char temp_input[200];
	
	puts("\nWhat would you like to read: ");
	gets(temp_input);
	if(temp_input == "book")
	{
		puts("\nThe text inside the book swirls and twists in an unfamiliar language. \nYou do successfully figure out the\
				author's name is Marellius Cam.");
		close();
	}
	if(temp_input == "letter")
	{
		puts("""\n\n
			Dear Marellius,	
				
				It has come to my attention that you have been dabbling in the Necrotic Arts.
			I have decided to remove you from the council and hereby disband your committee and 
			you shall be removed from the castle. Please take what you wish from the lower levels
			but be gone before next week or you will be forcefully extracted.
									
									-The Advisor
			
			""");
		close();
	}
	else
	{
		puts("You cannot see anything to read... ");
		close();
	}

}/* end 'act_read' */

void act_attack(void)
{
	int x;
	int final;
	char temp_input[200];
	char weapon[200];
	int health;
	int enemy_health;
	int health_2;
	int enemy_health_2;
	p_valid="\nWhat do you want to attack: ";
	p_invalid="\nThere is nothing to attack... ";

	switch(room)
	{
		case 6:
		{
			puts("%c",p_valid);
			gets(temp_input);
			if(temp_input == "zombie")
			{
				enemy_health=20;
				health=30;
				health_2=health;
				enemy_health_2=enemy_health;
				
				seedrnd();
				x=rnd_10(10);
				
				puts("\nWhat do you want to attack with: ");
				gets(weapon);
				if(weapon == "sword")
				{
					final=x+15;
				}
				if(weapon == "hands" ||weapon == "hand" ||weapon == "fist" ||weapon == "fists" ||weapon == "self")
				{
					final=x;
				}
				
	/* start combat loop */	while(enemy_health > 1 && enemy_health_2 > 1 && health > 1 && health_2 > 1)
				{
					printf("\n\"You attack and deal %i damage!\"",final);
					enemy_health_2=(enemy_health - final);

					seedrnd();
					x=rnd_10(8);
					
					printf("\n\"The Zombie attacks and deals %i damage!\"",x);
					health_2=(health - x);

					health=health_2;
					enemy_health=enemy_health_2;
				}
				if(health == 0 || 1)
					printf("\n\"You have died......................\nwell good thing this is a game and I'm too lazy to \
							incorporate death so you can keep going.  ^_^\"");
				if(enemy_health == 0 || 1)
				{
					zombie=0;
					puts("\n\"You killed the Zombie\"");
				}
			}
			else
			{
				puts("\nThat is not a valid target. Try attacking the Zombie");
			}
			close();
			break;
		}/* end '6' case */
		case 9:
		{
			printf("%c",p_valid);
			gets(temp_input);
			if(temp_input == "skeleton")
			{
				enemy_health=30;
				health=30;
				health_2=health;
				enemy_health_2=enemy_health;
				
				seedrnd();
				x=rnd_10(10);
				
				puts("\nWhat do you want to attack with: ");
				gets(weapon);
				if(weapon == "sword")
				{
					final=x+15;
				}
				if(weapon == "hands" ||weapon == "hand" ||weapon == "fist" ||weapon == "fists" ||weapon == "self")
				{
					final=x;
				}
				
	/* start combat loop */	while(enemy_health > 1 && enemy_health_2 > 1 && health > 1 && health_2 > 1)
				{
					printf("\n\"You attack and deal %i damage!\"",final);
					enemy_health_2=(enemy_health - final);

					seedrnd();
					x=rnd_10(10);
					
					printf("\n\"The Skeleton attacks and deals %i damage!\"",x);
					health_2=(health - x);

					health=health_2;
					enemy_health=enemy_health_2;
				}
				if(health == 0 || 1)
					printf("\n\"You have died......................\nwell good thing this is a game and I'm too lazy to \
							incorporate death so you can keep going.  ^_^\"");
				if(enemy_health == 0 || 1)
				{
					skeleton=0;
					puts("\n\"You killed the Skeleton\"");
				}
			}
			else
			{
				puts("\nThat is not a valid target. Try attacking the Skeleton");
			}
			close();
			break;
		}/* end case '9' */

		default:
		{
			printf("%c",p_invalid);
			close();
			break;
		}

	}/* end 'room' switch */
	close();
}


void act_wear(void)
{
	char temp_input[200];
	
	puts("\nWhat would you like to equip: ");
	gets(temp_input);
	if(temp_input == "amulet")
	{
		puts("\n\"Amulet Equipped\"");
		amulet_equip=1;
	}
	if(temp_input == "ring")
	{
		puts("\n\"Ring Equipped\"");
		ring_equip=1;
	}
	else
		printf("\nYou expect to equip that? NO.\nTry equipping something else");

	close();
}


void act_use(void)
{
	char temp_input[200];
	char temp_y-n[200];
	char spell[200];

	puts("\nWhat would you like to use: ");
	gets(temp_input);
	if(temp_input == "book")
	{
		puts("\nWould you like to cast a spell with the book? (y/n): ");
		gets(book_y-n);
		if(temp_y-n == 'y')
		{
			printf("""\n\n
				PICK A SPELL:
		_______________________________________________
               |Sparkle: Make everything magic -\"[N/A]\"-    |
	       |______________________________________________|
	       |Bubbles: Blow bubbles at something -\"[N/A]\"-|
	       |______________________________________________|
	       |Light: Generate an aura of light -\"light\"-  |
	       |______________________________________________|
	       			""");
			gets(spell);
			if(spell == "light");
			{
				puts("\nA small glowing sphere of light glows around you.\
						\nYou don't need your candle anymore...");
				spell_light=1;
				light=1;
			}
			else
			{
				puts("\nSparks fizzle but nothing happens.");
			}
		}
		else
		{
			break;
		}
		close();
	}
	/* start for candle */
	if(temp_input == "candle")
	{
		puts("\nWould you like to shed light with the candle? (y/n): ");
		gets(temp_y-n);
		if(temp_y-n == 'y')
		{
			puts("\nA soft blue-ish glow fills the room");
			light=1;
		}
		else
			break;
	}
	/* start for bones */
	if(temp_input == "bones")
	{
		if(room == 9)
		{
			puts("\nThe bones glow and small symbols appear on them.");
		}
		else
		{
			puts("\nNothing happens...");
		}
	}/*stop bones*/
	
	/* start for rope */
	if(temp_input == "rope")
	{
		if(room == 13)
		{
			puts("\nJust climb the stairs...");
		}
		else
		{
			puts("\nYou might want to just hang onto this...");
		}

	}

	/* start for ring */
	if(temp_input == "ring")
	{
		if(room == 9 && bones == "yes")
		{
			puts("\nThe ring glows lightly and at the same time the bones' symbols shine.");
		}
		else
		{
			puts("\nThe ring glows softly in the dim light.");
		}
		close();
	}
	close();
}

void act_open(void)
{
	char temp_input[400];

	gets(temp_input);
	
	if(room == 7 && temp_input == "door" && ring == "yes")
	{
		puts("\nThe door swings open and a cold breeze hits your face.");
		door = "unlocked";
	}
	else
	{
		puts("\nYou either not open that or you are using the wrong command");
	}
	close();
}




/***------------------------------STOP ACTION FUNCTIONS---------------------------------***/
void help_input(void) 
{
	printf("\nValid Input statements would be: ");
	printf("\n\"take [item]\"");
	printf("\n\"read [item]\"");
	printf("\n\"attack [target_name] [weapon]\"\tEx. \"attack dire_boar sword\"");
	printf("\n\"wear [item]\"");
	printf("\n\"use [item] [target/action]\"\tEx. \"use key door\"");
	printf("\n\"open [target]\"");
	/* puts("\n\"destroy [target]\" (NOT RECOMMENDED ON INVENTORY ITEMS)"); */
	/* puts("\n\"put [item] [target]\""); */
	printf("\n\n\"Valid Commands would be: \"");
	printf("\n\"backpack\" this prints your current items");
	printf("\n\"look\" echo room dialogue");
	printf("\n\"quit\" quits the game");
	/* && DECIDE ON COMMANDS && */

} /** END 'help' function **/

/* start backpack */
void backpack(void)
{
	printf("\nBACKPACK: ")

	if(letter == "yes")
		printf("\nA Letter");

	if(candle == "yes")
		puts("\nA Candle");

	if(book == "yes")
		puts("\nA Book");

	if(sword == "yes")
		puts("\nA Sword");

	if(amulet == "yes")
		puts("\nAn Amulet");

	if(moss == "yes")
		puts("\nSome Moss");

	if(key == "yes")
		puts("\nA Key");

	if(bones == "yes")
		puts("\nSome Bones");

	if(rope == "yes")
		puts("\nSome Rope");

	if(ring == "yes")
		puts("\nA Ring");
	close();
}



/***--------------------------------------START DIALOGUES--------------------------------***/
//char room_1_input(void)
//{
	///* set the backpack */
	//letter="no";
	//candle="no";
	//book="no";
	//sword="no";
	//amulet="no";
	//moss="no";
	//key="no";
	//bones="no"
	//rope="no";
	//ring="no";

	//door="locked";

	//char temp_char[30]; /* temp variable */
	///* start working */
	
	//close();
	//gets(temp_char);
	

	///* begin checking input */
	//if(temp_char == 'n')
	//{}/** %!%!%!%!%! FINISH THIS %!%!%!%!%! **/


	
	//return(room_1_output);
//}




/* ------------------------------------------------------ */

/* $$ DIALOGUE $$ */
	
char room_1_dialogue[200] = \ /* room 1 (see map) */
{
	"\n\nYou are in a large cavern, there is a hole in the ceiling and some water drips down."\ 
	"\nYou look around and see two openings in the wall."\
	"\nThe west one has moss covering the walls and the north one has water dripping from the ceiling."\
	"\nIt appears the west one winds around and the north one travels straight.",\
	
	"\nResting on a smooth rock is a candle that appears to eminate a blue glow and burns despite the water." /* Item Statement */
};

	
char room_2_dialogue[400] = \ /* room 2 (see map) */
{
	"\n\nYou enter a smaller cavern that is covered all over by moss."\
	"\nThe moss hangs from the ceiling and is wet and sticky."\
	"\nThree openings are visible."\
	"\nTo the west there is a curving passage heavier in moss."\
	"\nThere is the opening south you just crawled from."\
	"\nTo the north there is a bricked passage that is lit and moss-free.",\
	
	"\nThere is what appears to be a letter caught in the moss by the opening you just crawled out of." /* Item Statement */
};

char room_3_dialogue[400] = \ /* room 3 (see map) */
{
	"\n\nAs you walk the tunnel widens into a large brick corridor."\
	"\nThere are other blue candles here mounted firmly on the walls providing an eerie light."\
	"\nTo the east lies an opening to a small room with a broken door."\
	"\nTo the south lies the path from whence you came."\
	"\nTo the north lies a small room revealed behind a leaning bookshelf.",\
	
	"\nBookshelves line the far wall and infront of a fallen one lies a book that catches your eye." /* Item Statement */
};


char room_4_dialogue[400] = \ /* room 4 (see map) */
{
	"\n\nYou look around and see that the room is for storage."\
	"\nBoxes line  the walls and broken pieces of items and shards of wood are strewn about."\
	"\nTo the west is the opening to the room of books."\
	"\nTo the south is another small storage room.",\
	
	"\nWhile looking around you notice the hilt of a sword poking out of a box." /* Item Statement */
};
	
	
char room_5_dialogue[400] = \ /* room 5 (see map)  */
{
	"\n\nIn this cramped room the bricks are falling out and dirt has poured in to a corner."\
	"\nThe only opening is to the north from whence you came."\
	"\nA small pool of water has formed and appears to be slowly growing.",\
	
	"\nThere is a small jewelry box sitting on the ground cracked open with an amulet poking out." /* Item Statement */
};


char room_6_dialogue[400] = \ /* room 6 (see map)  */
{
	"\n\nMoss hangs from the celing and clings to nearly every surface."\
	"\nYou look to the south and see it is the only way out of the cavern."\
	"\nNo candles are here yet it doesn't seem to be very dark.",\

	"\nAside from you and a larger pile of moss in the center it is an otherwise empty room." /* Item Statement */
};


char room_7_dialogue[400] = \ /* room 7 (see map) */
{
	"\n\nThis is an out-of-place doorway reminiscent of olden days."\
	"\nIt is made of stone bricks that are a comfortable dark-grey colour and are seamlessly connected."\
	"\nThere is a small keyhole in the door.",\
	
	"\nYou try to open the door but it won't budge." /* * * Remove after unlocking * * */

};
	

char room_8_dialogue[400] = \ /* room 8 (see map) */
{
	"\n\nYou are in a room that appears to be made of a solid piece of black stone."\
	"\nTo the south is the way you came.",\

	"\nIn the middle is a key lying by itself on the ground." /* Item Statement */
};


char room_9_dialogue[400] = \ /* room 9 (see map) */
{
	"\n\nA massive brick room lit by many of the blue candles lies before you."\
	"\nTo the west lies a sagging door with no light beyond it."\
	"\nTo the north is a small staircase leading to another dark area."\
	"\nBack south is the door you came through.",\
	
	"\nA small pile of burnt bones lie on the ground." /* Item Statement */
};


char room_10_dialogue_1[400] = \ /* room 10 !BEFORE USING CANDLE! (this can substitute for any dark room) */
{
	"\n\nIt is too dark to see anything."\
	"\nTry using a light source to provide visibility."
};


char room_10_dialogue_2[400] = \ /* room 10 !AFTER USING CANDLE! (see map) */
{
	"\n\nIt is very dim even as you take out your candle."\
	"\nIt is the bottom of some well-like structure."\
	"\nTo the south lies the large brick room.",\

	"\nOn the ground is a length of cut rope." /* Item Statement */
};


char room_11_dialogue[400] = \ /* room 11 (see map) */
{
	"\n\nIt is very dim and cold in here, it doesn't feel safe..."\
	"\nThere are ruined candle sockets on the wall and the walls themselves are crumbling."\
	"\nMost of the doors have collapsed save two."\
	"\nThe opening to the north appears to lead to a cell of some sort."\
	"\nThe opening to the east reminds you of the antechambers or large castles."
};


char room_12_dialogue[400] = \ /* room 12 (see map) */
{
	"\n\nThe cell looks like it has not been used in ages."\
	"\nTo the south is the door and it is the only opening.",\
	
	"\nOn the ground on a skeletal finger is a smooth ring." /* Item Statement */
};


char room_13_dialogue[400] = \ /* room 13 (see map) */
{
	"\n\nInstead of the expected antechamber you see a massive staircase stretch before you going east."\
	"\nAside from the staircase the room is fairly barren."
};


char room_14_dialogue[400] = \ /* room 14 (see map) LAST ROOM! */
{
	"\n\nAs you ascend the massive staircase, stepping past hole you step into the light."\
	"\n......"\
	"\nThe bright light temporarily blinds you as you step out into the outside."\
	"\nYou look around and see that you are in the ruins of a massive castle."\
	"\nNot knowing what to do you lay down and get your much deserved sleep."
};

char intro_print(void)
{
	
	printf("""\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f
*############################################################*
$     _     __              ___  _     ___ ___  _      ___   $
$    /\\   | \\   \\     / |    |\\  |  |   |  |\\  | |      $
$   /==\\  |   |   \\   /  |--- | \\ |  |   |  | \\ | |---   $
$  /    \\ |__/     \\_/   |___ |  \\|  |  _|_ |  \\| |___   $
$____________________________________________________________$
$                             |                              $
$ By: Sean Hinchee            | Version: 1.0                 $
$                             |                              $
$ Email: henesy.dev@gmail.com | Read the README.txt!         $
$                             |                              $
*############################################################*
\n""");
}

/* ------------------------------------------------------------ */



/* start look */
void look(void)
{
	int temp_int;

	temp_int = room;

	switch(temp_int)
	{
		case 1:
		{
			printf("\n%s", room_1_dialogue);
			close();
			break;
		}
		case 2:
		{
			printf("\n%s", room_2_dialogue);
			close();
			break;
		}
		case 3:
		{
			printf("\n%s", room_3_dialogue);
			close();
			break;
		}
		case 4:
		{
			printf("\n%s", room_4_dialogue);
			close();
			break;
		}
		case 5:
		{
			printf("\n%s", room_5_dialogue);
			close();
			break;
		}
		case 6:
		{
			printf("\n%s", room_6_dialogue);
			close();
			break;
		}
		case 7:
		{
			printf("\n%s", room_7_dialogue);
			close();
			break;
		}
		case 8:
		{
			printf("\n%s", room_8_dialogue);
			close();
			break;
		}
		case 9:
		{
			printf("\n%s", room_9_dialogue);
			close();
			break;
		}
		case 10:
		{
			if(light == 1)
			{
				printf("\n%s", room_10_dialogue_2);
			}
			else
			{
				printf("\n%s", room_10_dialogue_1);
			}
			break;
		}
		case 11:
		{
			printf("\n%s", room_11_dialogue);
			close();
			break;
		}
		case 12:
		{
			printf("\n%s", room_12_dialogue);
			close();
			break;
		}
		case 13:
		{
			printf("\n%s", room_13_dialogue);
			close();
			break;
		}
		case 14:
		{
			printf("\n%s", room_14_dialogue);
			close();
			break;
		}
		default:
		{
			printf("\nSomehow you managed to break the room number counter...I dun even....\nKUDOS TO YOU! Have a cat face:");
			printf("\n :3 ");
			break;
		}
	}/* end switch */

}/* end look */


/*** ----------------------------------------------------------------------------------------------- ***/
/** START PROGRAM **/

int main()
{	
	
	/* ### Start Main ### */
	temp_int=0;


	printf("Welcome to Adventine\n");
	printf("Please enter your desired character name: "); /* getting name input */
	gets(name);
	printf("\nAre you sure you want your name to be: %s? (y/n)",name);
	gets(temp_char);
	
	/** Start 'while' loop **/

	while(temp_char != 'y');	
	{
		printf("\nPlease enter your desired character name: "); /* getting name input */
		gets(name);
	}
	
	/** End 'while' loop **/
	
	printf("Hello %s!",name);

	printf("\nEnter '?' at any time to see the help screen ");
	
	/* |START| ROOM 1 */

	printf("%s",room_1_dialogue);
	close();
	

	/* |END| ROOM 1 */

	/* RETURN JAZZ */
	return(0);
}

