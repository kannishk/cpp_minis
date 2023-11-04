#include<iostream>
#include<fstream>

using namespace std;

string convertHand(string);
void collectNumbers(string);
void organizeCards();
void removeCards();
bool straight();
bool flush(string);
bool pairs();
int ofaKind();
int handRank(string);
int playPoker(string, string);
int compareRank(int, int);
int compareHands(int, int, int, int);
int cardNumArray[5] = {}, handHigh = 0, totalHigh = 0;

int main(){
    int player1Wins = 0, player2Wins = 0, winner = 0;
    string hands, hand1, hand2;

    ifstream file("poker.txt");
    while(getline(file, hands)){
        hand1 = hands.substr(0, 14);
        hand2 = hands.substr(15, 14);
        winner = playPoker(hand1, hand2);
        if(winner==1){
            player1Wins++;
        }else{
            player2Wins++;
        }
    }

    cout << "Player 1 Wins: " << player1Wins << endl;
    cout << "player 2 wins " << player2Wins << endl;
}

string convertHand(string hand){
    char cArray[5] = {'T','J','Q','K','A'};
    string sArray[5] = {"10","11","12","13","14"};
    for (int i = 0; i <= hand.length() - 2;i++){
        for (int j = 0; j <= 4;j++){
            if(hand[i]==cArray[j]){
                hand.replace(i, 1, sArray[j]);
            }
        }
    }
    return hand;
}

void collectNummbers(string hand){
    string subHand;
    int j = 0, index = 0;

    totalHigh = 0;
    for (int i = 0; i <= hand.length() - 1;i++){
        if(hand[i]==' '){
            continue;
        }
        if(hand[i]=='D' || hand[i]=='C' || hand[i]=='H'|| hand[i]=='S'){
            cardNumArray[index] = j;
            subHand = "";
            index++;
            continue;
        }
        subHand += to_string(hand[i] - '0');
        j = stoi(subHand);
    }

    for (int i = 0; i <= 4;i++){
        if(cardNumArray[i]>totalHigh){
            totalHigh = cardNumArray[i];
        }
    }
}

void organizeCards(){
    int temp = 0;
    for (int i = 0; i <= 4;i++){
        for (int j = i + 1; j <= 4;j++){
            if(cardNumArray[j]<cardNumArray[i]){
                temp = cardNumArray[i];
                cardNumArray[i] = cardNumArray[j];
                cardNumArray[j] = temp;
            }
        }
    }
}

void removeCards(){
    for (int i = 0; i <= 3;i++){
        if(cardNumArray[i]==cardNumArray[i+1] && cardNumArray[i+1]==cardNumArray[i+2]){
            cardNumArray[i] = 0;
            cardNumArray[i + 1] = 0;
            cardNumArray[i + 2] = 0;
        }
    }
}

bool straight(){
    for (int i = 0; i <= 2;i++){
        if(cardNumArray[i]==cardNumArray[i+1]-1){
            continue;
        }
        else{
            return false;
        }
    }

    if(cardNumArray[3]==5 && cardNumArray[4]==14){
        return true;
    }
    else if(cardNumArray[3]==cardNumArray[4]-1){
        return true;
    }else{
        return false;
    }

}

bool flush(string hand){
    string temp = hand;
    temp.erase(remove_if(temp.begin(), temp.end(), ::isspace), temp.end());
    temp.erase(remove_if(temp.begin(), temp.end(), ::isdigit), temp.end());
    for (int i = 0; i <= 3;i++){
        if(temp[i]==temp[i+1]){
            continue;
        }else{
            return false;
        }
    }
    return true;
}

int ofaKind(){
    int count = 0;
    for (int i = 0; i <= 2;i++){
        if(cardNumArray[i]==cardNumArray[i+1]&&cardNumArray[i+1]==cardNumArray[i+2]){
            count++;
        }
    }

    if(count ==2){
        handHigh = cardNumArray[1];
    }else if(count ==1){
        handHigh = cardNumArray[2];
        removeCards();
        organizeCards();
        return 3;
    }
    return 3;
}

bool pairs(){
    int count = 0;
    for (int i = 0; i <= 3;i++){
        if(cardNumArray[i]==0){
            count++;
            continue;
        }
        if(cardNumArray[i]==cardNumArray[i+1]){
            if(count<3){
                handHigh = cardNumArray[i];
            }
            cardNumArray[i] = 0;
            cardNumArray[i + 1] = 0;
            return true;
        }
    }
    return false;
}

int handRank(string hand){
    bool flushTrue = flush(hand);

    if(straight()){
        if(flushTrue){
            if(cardNumArray[0]==10){
                return 9;
            }else{
                return 8;
            }
        }else{
            return 4;
        }
    }else if(flushTrue){
        return 5;
    }

    int kind = ofaKind();

    if(kind==4){
        return 7;
    }else if(kind ==3){
        if(pairs()){
            return 6;
        }else{
            return 3;
        }
    }else if(pairs()){
        if(pairs()){
            return 2;
        }else{
            return 1;
        }
    }else{
        return 0;
    }
}


int playPoker(string hand1, string hand2){
    int rank1 = 0, rank2 = 0, winner = 0, handHigh1 = 0, totalHigh1 = 0, handHigh2 = 0, totalHigh2 = 0;

    hand1 = convertHand(hand1);
    collectNumbers(hand1);
    organizeCards();
    rank1 = handRank(hand1);
    handHigh1 = handHigh, totalHigh1 = totalHigh;

    hand2 = convertHand(hand2);
    collectNumbers(hand2);
    organizeCards();
    rank2 = handRank(hand2);
    handHigh2 = handHigh, totalHigh2 = totalHigh;

    winner = compareRank(rank1, rank2);
    if(winner==3){
        return compareHands(handHigh1, totalHigh1, handHigh2, totalHigh2);
    }else{
        return winner;
    }
}

int compareRank(int rank1, int rank2){
    if(rank1>rank2){
        return 1;
    }else if(rank2>rank1){
        return 2;
    }else{
        return 3;
    }
}

int compareHands(int handHigh1, int totalHigh1, int handHigh2, int totalHigh2){
    if(handHigh1 > handHigh2){
        return 1;
    }else if(handHigh2>handHigh1){
        return 2;
    }else{
        if(totalHigh1>totalHigh2){
            return 1;
        }else{
            return 2;
        }
    }
}