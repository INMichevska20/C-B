#include <string>
#include <vector>

using namespace std;

struct biologyTest
{
    string franceQuestions[7] =
    {
        "", 
        "",
        "", 
        "",
        "",
        "",
        ""
    };

    
    bool biologyAnswers[20] = { true, true, false, true, false, false, true };
    vector<bool> isCorrect = { 0 };
}franceVar;

int testScore = 0;
int select = 0;