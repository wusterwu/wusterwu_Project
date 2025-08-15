#include "CommonLibrary.h"

int main()
{
// 	string strTemp = "hello";
// 	vector<string> vect;
	Calculate & instance = Calculate::getInstance();
// 	int count = instance.stringToSeperate(strTemp,",",vect);
// 	for (int i = 0; i < count; i++)
// 	{
// 		cout << vect.at(i) <<endl;
// 	}
// 	string strTemp1 = "12";
// 	string strTemp2 = "0x1A";
// 	cout << instance.stringToDecimal(strTemp1)<<endl;
// 	cout << instance.stringToDecimal(strTemp2,HEXTYPE)<<endl;
// 
// 	string strTemp3 = "HEllo";
// 	cout << instance.stringToUper(strTemp)<<endl;
// 	cout << instance.stringToLower(strTemp3)<<endl;
// 
// 	int t1 = 10;
// 	int t2 = 0x1B;
// 	cout << instance.Dec2String(t1)<<endl;
// 	cout << instance.Hex2String(t2) <<endl;
// 
// 	string t3 = "aabbcdbd";
// 	cout << instance.toDelteSubStr(t3,"b")<<endl;
// 	cout << instance.String2ReplaceSubStr_All(t3,"b","?&")<<endl;
// 	double t4 = 3.1444;
// 	string t5 = "6.28";
// 	cout << instance.DoubleToString(t4,0) <<endl;
// 	cout << instance.stringToDouble(t5) <<endl;
// 
// 	cout << instance.genRandomData(1,10) <<endl;
// 	cout << instance.genRandomData() <<endl;
	int arr[10] = {1,8,6,4,2,9,7,13,13,10};
	instance.arraySort(arr,10);
	for (int i = 0 ; i < 10 ;i++)
	{
		cout << arr[i] <<endl;
	}
	return 0;
}