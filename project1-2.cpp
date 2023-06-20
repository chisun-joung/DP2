#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <tuple>
using namespace std;

//strategy 패턴

struct IPredictor
{
    virtual void predict(int& x, int& y, int& z) = 0;
    virtual ~IPredictor() {}
};

class RandomPredictor : public IPredictor
{
public:
    virtual void predict(int& x, int& y, int& z)
    {
         do {
            x = rand() % 10;
            y = rand() % 10;
            z = rand() % 10;
        } while (x == y || y == z || z == x);
    }
};


class BaseBallGame
{
    typedef tuple<int, int, int> INPUT;
    typedef tuple<int, int> RESULT;
    vector<pair<INPUT, RESULT>> v;
    IPredictor* predictor = nullptr;

public:
    BaseBallGame() { srand((unsigned)time(0)); }
    void set_predictor(IPredictor* p) { predictor = p; }
    void run()
    {
        while(1)
        {
            //-----------------------------------
            // 이전의 결과가 감긴 vector v를 참고해서 
            // 사용자가 생각한 숫자를 예측해 냅니다. 
            // 현재 구현은 무조건 랜덤 입니다. 
            int x = 0, y = 0, z = 0;
            if(predictor == nullptr) break;
            predictor->predict(x, y, z);
            //-----------------------------------



            cout <<  "당신이 생각한 숫자는" << x 
            << ", " << y << ", " << z << "입니까?" << endl;
            int strike = 0, ball = 0;
            cout << "strike 개수 : ";
            cin >> strike;
            if (strike == 3)
            {
                cout << "성공 !" << endl;
                break;
            }
            cout << "ball 개수 : ";
            cin >> ball;
            v.push_back(make_pair(INPUT(x, y, z), RESULT(strike, ball)));
            dump();
            
        }

       
    }

    void dump()
    {
        printf("-----------------------------------------------\n");
        printf("입력값 s b\n");
        for (auto& p : v)
        {
            printf("%d %d %d : %d %d\n", 
                get<0>(p.first), get<1>(p.first), get<2>(p.first), 
                get<0>(p.second), get<1>(p.second));                
        }
        printf("-----------------------------------------------\n");
    }

};




int main()
{
    BaseBallGame bbg;
    RandomPredictor rp;
    bbg.set_predictor(&rp);
    bbg.run();
}