#pragma once
//，，，，，，，，，，，，，，，，，，，，，，，，，，，，，， 潤更悶
#define maxsize 50
#define limit -842150451
struct rankedlist//，，，，，，，，，，，，，，，，，，，，，，乏會燕
{
	int ranlist[maxsize];
	int length;
};
struct linklist//，，，，，，，，，，，，，，，，，，，，，，，，全燕
{
	int data;
	struct linklist* next;
};
//，，，，，，，，，，，，，，，，，，，，，，，，，，，， 乏會燕痕方
void craftlist(struct rankedlist*& list);//，，，，，，，，幹秀乏會燕
void addlistnum(struct rankedlist*&list);//，，，，，，葎乏會燕耶紗峙
void fun(struct rankedlist*& list);//，，，，，，，，，，，，電會痕方
void operationranklist();//，，，，，，，，，，，，，，，，，塰佩痕方
//，，，，，，，，，，，，，，，，，，，，，，，，，，，，， 全燕痕方
struct linklist* craftlink();//，，，，，，，，，，，，，，，幹秀全燕
void addlinklistnode(struct linklist* link);// ，，，，，耶紗全燕准泣
int traversallinklist(struct linklist* link);//，煽演全燕旺由柴准泣方
void invertedorder(struct linklist*& link);//，，，，宜會電双全燕准泣
void descendingorder(struct linklist*& link);//，，，，，弓受肝會補竃
void destroylist(struct linklist*& link);//，，，，，，，，，��支全燕
void ListPrint(struct linklist*& link);//，，，，，，，，，，嬉咫全燕
void operationlinklist();//，，，，，，，，，，，，，，，，，塰佩痕方   
/*
           oooo
           `888
oo.ooooo.   888   .oooo.   oooo    ooo
 888' `88b  888  `P  )88b   `88.  .8'
 888   888  888   .oP"888    `88..8'
 888   888  888  d8(  888     `888'
 888bod8P' o888o `Y888""8o     .8'
 888                       .o..P'
o888o                      `Y8P'

*/
/*
                                              __                 __
                                             /\ \               /\ \
 __  __  __  __  __  __  __  __  __       ___\ \ \___      __   \_\ \     __      ___         ___    ___     ___ ___
/\ \/\ \/\ \/\ \/\ \/\ \/\ \/\ \/\ \     /'___\ \  _ `\  /'__`\ /'_` \  /'__`\  /' _ `\      /'___\ / __`\ /' __` __`\
\ \ \_/ \_/ \ \ \_/ \_/ \ \ \_/ \_/ \ __/\ \__/\ \ \ \ \/\  __//\ \L\ \/\ \L\.\_/\ \/\ \  __/\ \__//\ \L\ \/\ \/\ \/\ \
 \ \___x___/'\ \___x___/'\ \___x___/'/\_\ \____\\ \_\ \_\ \____\ \___,_\ \__/.\_\ \_\ \_\/\_\ \____\ \____/\ \_\ \_\ \_\
  \/__//__/   \/__//__/   \/__//__/  \/_/\/____/ \/_/\/_/\/____/\/__,_ /\/__/\/_/\/_/\/_/\/_/\/____/\/___/  \/_/\/_/\/_/


*/