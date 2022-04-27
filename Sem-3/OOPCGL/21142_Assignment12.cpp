/*

  Samarth Ramkrushna Kamble (21142 F1-Batch)
  Assignment-12
  OOPCG Laboratory
  Date:- 15/12/21

  Wrie a program in C++ to use mpp associative container. The keys will be the names of states and
  the values will be the populations of the states. When the program runs,
  the user is prompted to type the name of a state.
  The program then looks in the mpp,
  using the state name as an index and returns the population of the state.
*/

#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

string capitalize(string &s)
{
  string tmp = "";
  for (auto &ch : s)
  {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
      tmp += (char)(ch & (~(1 << 5)));
  }
  s = tmp;
  return s;
}

map<string, long long>::iterator findMyState(string &s, map<string, long long> &mp)
{
  map<string, long long>::iterator state;
  map<string, long long>::iterator itr = mp.begin();
  int cnt = 0;

  for (itr = mp.begin(); itr != mp.end(); itr++)
  {
    int tmp = itr->first.find(s);
    if (tmp != string::npos)
    {
      state = itr;
      cnt++;
    }
  }
  if (cnt > 1)
  {
    cout << "UNABLE TO IDENTIFY!!!!\nPLEASE RE-ENTER";
    return mp.end();
  }
  else if (cnt == 0)
  {
    cout << "\nSTATE NOT FOUND";
    return mp.end();
  }
  else
    return state;
}

int main()
{
  map<string, long long> mp;            // map created
  map<string, long long>::iterator itr; // Iterator for map

  mp.insert(make_pair("MAHARASHTRA", 12765123));

  mp.insert({"MAHARASHTRA", 112374333});
  mp.insert({"GUJARAT", 60439692});
  mp.insert({"RAJASTHAN", 68548437});
  mp.insert({"ODISHA", 41974219});
  mp.insert({"HARYANA", 25351462});
  mp.insert({"JAMMUKASHMIR", 12267032});
  mp.insert({"UTTARAKHAND", 10086292});
  mp.insert({"UTTARPRADESH", 199812341});
  mp.insert({"HIMACHALPRADESH", 6864602});
  mp.insert({"ANDHRAPRADESH", 49577103});
  mp.insert({"SIKKIM", 610577});
  mp.insert({"NAGALAND", 1978502});
  mp.insert({"TAMILNADU", 72147030});
  mp.insert({"KERALA", 33406061});
  mp.insert({"GOA", 1458545});

  // string p = "ABCD";
  // string tmp = capitalize(p);

  int ch;
  string state, cpState;

  while (1)
  {
    cout << "\nMENU\n1.Search State\n2.Add state\n3.Modify population\n4.Exit\nEnter your choice:";
    int tmp;
    cin >> ch;
    switch (ch)
    {

    case 1:
      cout << "\nEnter State Name to search:";
      cin >> state;
      cpState = state;
      state = capitalize(state);
      itr = findMyState(state, mp);

      if (itr != mp.end())
      {
        cout << "\n Search Found\n";
        if (cpState.length() != itr->first.length())
          cout << itr->first << " has population of approx. " << itr->second << "\n";
        else
          cout << cpState << " has population of approx. " << itr->second << "\n";
      }
      cout << setw(100) << setfill('_') << endl;
      break;

    case 2:
      cout << "Enter state: ";
      cin >> state;
      cout << "Enter population: ";
      cin >> tmp;
      mp.insert({capitalize(state), tmp});
      break;

    case 3:
      cout << "Enter state: ";
      cin >> state;
      itr = findMyState(capitalize(state), mp);
      cout << "ENTER POPULATION: ";
      cin >> tmp;
      if (itr == mp.end())
        cout << "\nNO STATE FOUND!!";
      else
        itr->second = tmp;
      break;

    case 4:
      cout << "\nTHANK YOU!!!";
      abort();
    }
  }

  return 0;
}
