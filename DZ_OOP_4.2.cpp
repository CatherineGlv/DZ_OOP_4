#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>

// задание подсмотрела в интернете, т.к. сама не во всем догоняю

using namespace std;

int randd()
{
    return rand() % 10 + 1;
}

int main()
{
    int n;
    
    cout << "Enter number 1 - 10: ";
    cin >> n;

    vector<int> v(n);

    generate(v.begin(), v.end(), randd);
    
    set<int> s(v.begin(), v.end());

    cout << "Total different numbers: " << s.size() << endl << "They are: ";
    
    copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
   
    cout << endl;

    return 0;
}