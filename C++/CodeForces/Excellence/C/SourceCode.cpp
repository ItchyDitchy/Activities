#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    vector<string> words(T);
    vector<int> sentiments(T);
    for (int i = 0; i < T; i++)
        cin >> words[i];
    for (int i = 0; i < T; i++)
        cin >> sentiments[i];

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string sentence;
        cin >> sentence;

        int positiveCount = 0, negativeCount = 0;
        for (int j = 0; j < sentence.length() - 2; j++) {
            char initial = sentence[j];
            int sentiment = sentiments[initial-'A'];
            if (sentiment == 1)
                positiveCount++;
            else if (sentiment == -1)
                negativeCount++;
        }

        string sentiment = positiveCount > negativeCount ? "POSITIVE" :
                        negativeCount > positiveCount ? "NEGATIVE" :
                        "NEUTRAL";
        cout << sentiment << endl;
    }
    return 0;
}