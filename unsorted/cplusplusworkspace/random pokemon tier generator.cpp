#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<vector>
using namespace std;

// input for desired tier
string input;

// pair< Pokedex number, Pokemon name >
vector< pair< string, string> > OU_Tier;
vector< pair< string, string> > UU_Tier;

void initOU(){
    OU_Tier.push_back(make_pair("184","Azumarill"));
    OU_Tier.push_back(make_pair("625","Bisharp"));
    OU_Tier.push_back(make_pair("286","Breloom"));
    OU_Tier.push_back(make_pair("113","Chansey"));
    OU_Tier.push_back(make_pair("006","Charizard-X"));
    OU_Tier.push_back(make_pair("006","Charizard-Y"));
    OU_Tier.push_back(make_pair("036","Clefable"));
    OU_Tier.push_back(make_pair("534","Conkeldurr"));
    OU_Tier.push_back(make_pair("719","Diancie"));
    OU_Tier.push_back(make_pair("149","Dragonite"));
    OU_Tier.push_back(make_pair("196","Espeon"));
    OU_Tier.push_back(make_pair("530","Excadrill"));
    OU_Tier.push_back(make_pair("598","Ferrothorn"));
    OU_Tier.push_back(make_pair("445","Garchomp"));
    OU_Tier.push_back(make_pair("282","Gardevoir"));
    OU_Tier.push_back(make_pair("094","Gengar"));
    OU_Tier.push_back(make_pair("472","Gliscor"));
    OU_Tier.push_back(make_pair("658","Greninja"));
    OU_Tier.push_back(make_pair("130","Gyarados"));
    OU_Tier.push_back(make_pair("485","Heatran"));
    OU_Tier.push_back(make_pair("647","Keldeo"));
    OU_Tier.push_back(make_pair("646","Kyurem-Black"));
    OU_Tier.push_back(make_pair("645","Landorus"));
    OU_Tier.push_back(make_pair("645","Landorus-Therian"));
    OU_Tier.push_back(make_pair("381","Latias"));
    OU_Tier.push_back(make_pair("380","Latios"));
    OU_Tier.push_back(make_pair("473","Mamoswine"));
    OU_Tier.push_back(make_pair("630","Mandibuzz"));
    OU_Tier.push_back(make_pair("310","Manectric"));
    OU_Tier.push_back(make_pair("303","Mawile"));
    OU_Tier.push_back(make_pair("308","Medicham"));
    OU_Tier.push_back(make_pair("127","Pinsir"));
    OU_Tier.push_back(make_pair("195","Quagsire"));
    OU_Tier.push_back(make_pair("479","Rotom-Wash"));
    OU_Tier.push_back(make_pair("212","Scizor"));
    OU_Tier.push_back(make_pair("212","Mega Scizor"));
    OU_Tier.push_back(make_pair("545","Scolipede"));
    OU_Tier.push_back(make_pair("227","Skarmory"));
    OU_Tier.push_back(make_pair("235","Smearagle"));
    OU_Tier.push_back(make_pair("700","Sylveon"));
    OU_Tier.push_back(make_pair("663","Talonflame"));
    OU_Tier.push_back(make_pair("639","Terrakion"));
    OU_Tier.push_back(make_pair("642","Thundurus"));
    OU_Tier.push_back(make_pair("248","Tyranitar"));
    OU_Tier.push_back(make_pair("248","Mega Tyranitar"));
    OU_Tier.push_back(make_pair("134","Vaporeon"));
    OU_Tier.push_back(make_pair("003","Venusaur"));
    OU_Tier.push_back(make_pair("145","Zapdos"));

    OU_Tier.push_back(make_pair("065","Mega Alakazam"));
    OU_Tier.push_back(make_pair("342","Crawdaunt"));
    OU_Tier.push_back(make_pair("660","Diggersby"));
    OU_Tier.push_back(make_pair("701","Hawlucha"));
    OU_Tier.push_back(make_pair("214","Mega Heracross"));
    OU_Tier.push_back(make_pair("707","Klefki"));
    OU_Tier.push_back(make_pair("462","Magnezone"));
    OU_Tier.push_back(make_pair("490","Manaphy"));
    OU_Tier.push_back(make_pair("373","Salamence"));
    OU_Tier.push_back(make_pair("398","Staraptor"));
    OU_Tier.push_back(make_pair("642","Thundurus Therian"));
    OU_Tier.push_back(make_pair("641","Tornadus-Therian"));
    OU_Tier.push_back(make_pair("049","Venomoth"));
    OU_Tier.push_back(make_pair("461","Weavile"));
    OU_Tier.push_back(make_pair("718","Zygarde"));
}
void initUU(){

}
int main(){
    getline(cin,input);
    if(input == "OU"){
        initOU();
        int i = rand() % OU_Tier.size();
        srand(time(NULL));
        cout << OU_Tier[i].first << " " << " " << OU_Tier[i].second << endl;
    }

}
