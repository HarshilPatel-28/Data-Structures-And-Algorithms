#include <iostream>
using namespace std;
int getSquare(int n)
{
    int start = 0, end = n;
    long long int mid = start + (end - start / 2);
    long long int ans = -1;
    while (start <= end)
    {
        long long int sqrt = mid * mid;
        if (sqrt == n)
        {
            return mid;
        }
        else if (sqrt < n)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start / 2);
    }

    return ans;
}
double precision(int num, int precision, int tempSolu)
{
    double flag = 1;
    double ans = tempSolu;
    for (int i = 0; i < precision; i++)
    {
        flag = flag / 10;
        for (double j = ans; j * j < num; j += flag)
        {
            ans = j;
        }
    }

    return ans;
}
int main()
{
    int a;
    cout << "Enter the element you want to find square root:";
    cin >> a;
    double tempsolu = getSquare(a);

    cout << "square root of " << a << " is " << precision(a, 3, tempsolu);
    return 0;
}