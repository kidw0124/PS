#include <iostream>
#include <vector>
 
using namespace std;
 
bool isPrime(int n)
{
  if (n == 1)
    return false;
  for (int j = 2; j < n; j++)
  {
    if (n % j == 0)
      return false;
  }
  return true;
}
 
int main(void)
{
  int m = 0, n = 0, min = 0, sum = 0;
  cin >> m; cin >> n;
 
  for (int i = n; i >= m; i--)
  {
    if (isPrime(i))
    {
      sum += i;
      min = i;
    }
  }
  if (sum == 0)
    cout << -1 << endl;
  else
  {
    cout << sum << endl;
    cout << min << endl;
  }
  return 0;
}