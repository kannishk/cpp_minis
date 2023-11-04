#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime> 

using namespace std;

int main(){
    vector<int> cards = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    srand(time(0));
    // random_shuffle(cards.begin(), cards.end());

    vector< pair<int, int> > pairs;

    for (int i = 0; i < cards.size();i++){
        for (int j = i + 1; j < cards.size();j++){
            if(cards[i]==cards[j]){
                pairs.push_back({i, j});
            }
        }
    }

//:    sort(cards.begin(), cards.end());

    int score = 0;
    int tries = 0;
   
    const int maxTries = 10;


    while(pairs.size()>0 && tries <maxTries){
        for (int i = 0; i < cards.size();i++){
            if(cards[i]==-1){
                cout << "* ";
            }else{
                cout << cards[i] << " ";
            }
        }

        cout << endl;

        int first, second;

        cout << "Enter first and second ";
        cin >> first >> second;

        if(first<0 || first>=cards.size()|| second<0 || second>=cards.size() || first ==second){
            cout << "Invalid Input" << endl;
            continue;
        }

        if(cards[first]==cards[second]){
            cout<<"You got a match" << endl;
            pairs.erase(remove_if(pairs.begin(), pairs.end(), [&](pair<int, int> &p)
                                  { return p.first == first || p.second == first || p.first == second || p.second == second; }),
                        pairs.end());
            cards[first] = cards[second] = -1;
            score++;
        }else{
            cout << "No Match" << endl;
        }
    }

    cout << "Final Score" << score << " out of " << pairs.size() / 2 << " pairs found." << endl;

    if(tries>=maxTries){
        cout << "You have reached the maximum number of tries " << endl;
    }

    return 0;
}
