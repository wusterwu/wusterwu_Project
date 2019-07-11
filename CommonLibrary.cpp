#include "CommonLibrary.h"

Calculate::Calculate()
{
}
Calculate::~Calculate()
{
}
//注意在这里static就不能再写了
Calculate & Calculate::getInstance()
{
	static Calculate instance;
	return instance;
}

//字符串分割函数的实现
int Calculate::stringToSeperate(string strSrc, string strSpeator, vector<string>& strVect)
{
	int iStart = 0;
	int iEnd = 0;
	string strTemp = "";
	if(strSrc.size() == 0 || strSpeator.size() == 0 )
	{
		return CODE_STREMPTY;//原串为空则返回0
	}
	if(strSrc.find(strSpeator) == string::npos)
	{//只有一个字段
		strVect.push_back(strSrc);
		return 1;
	}
	//有多个字段的时候
	while (iEnd != string::npos)
	{
		iEnd = strSrc.find(strSpeator, iStart);
		if(iEnd == string::npos)
		{
			strTemp = strSrc.substr(iStart,strSrc.size());
			strVect.push_back(strTemp);
			break;
		}
		else
		{
			strTemp = strSrc.substr(iStart,iEnd - iStart);
			strVect.push_back(strTemp);
			iStart = iEnd + strSpeator.size();//更新起始位
		}
	}
	return strVect.size();
}

//字符串转换为数值
int  Calculate::stringToDecimal(const string strChar,DataScale data_type /*= DECIMAL*/)
{
	int Rect = CODE_DATAERROE;
	char *pStr = NULL;
	if(strChar == "")
	{
		return CODE_STREMPTY;
	}
	switch(data_type)
	{
	case DECIMAL:
		Rect = atoi(strChar.c_str());
		break;
	case HEXTYPE:
		Rect = (int)strtol(strChar.c_str(),&pStr,16);
		break;
	default:
		break;
	}
	return Rect;
}

//字符串全部转换为大写
string   Calculate::stringToUper(string strChar)
{
	int iLength = strChar.length();
	char cTemp = 'A';
	for (int i = 0; i < iLength ; i++)
	{
		cTemp = strChar.at(i);
		if (cTemp >= 'a' && cTemp <= 'z')
		{
			strChar.at(i) = (char)(cTemp + 'A' - 'a');
		}
	}
	return strChar;
}
//字符串全部转换为小写
string  Calculate::stringToLower(string strChar)
{
	int iLength = strChar.length();
	char cTemp = 'a';
	for (int i = 0; i < iLength ; i++)
	{
		cTemp = strChar.at(i);
		if (cTemp >= 'A' && cTemp <= 'Z')
		{
			strChar.at(i) = (char)(cTemp + 'a' - 'A');
		}
	}
	return strChar;
}

//将十进制的数据转换为字符串
string  Calculate::Dec2String(int decimal)
{
	string strTemp = "";
	char cTemp[50] = {0};
	sprintf(cTemp,"%d",decimal);
	strTemp = strTemp + cTemp;
	return strTemp;
}

//将十六进制的数据转换为字符串
string  Calculate::Hex2String(long hex)
{
	string strTemp = "";
	char cTemp[50] = {0};
	sprintf(cTemp,"%X",hex);
	strTemp = strTemp + cTemp;
	return strTemp;
}
//删除子字符串
string Calculate::toDelteSubStr(string strSrc,string strSub)
{
	int iStart = 0;
	if (strSrc == "" || strSub == "")
	{//如果原串或子串为空则返回原串
		return strSrc;
	}
	iStart = strSrc.find(strSub,0);
	if (iStart == string::npos)
	{//如果不存在这样的子字符串，则返回原串即可
		return strSrc;
	}
	while (iStart != string::npos)
	{
		strSrc = strSrc.erase(iStart,strSub.length());
		iStart = strSrc.find(strSub,0);
	}
	return strSrc;
}
//替换一个字符串的所有子串
string  Calculate::String2ReplaceSubStr_All(string strSrc,string strOldSub, string strNewSub)
{
	int iStartPos = 0;//旧子串的起始位置
	if (strSrc == "" || strOldSub == "" || strNewSub == "" || strOldSub == strNewSub)
	{//这里添加了替换的新串与原子串一样的处理，否则被误输入造成死循环
		return strSrc;
	}
	iStartPos = strSrc.find(strOldSub);
	if (iStartPos == string::npos)
	{
		return strSrc;
	}
	while (iStartPos != string::npos)
	{
		strSrc = strSrc.replace(iStartPos,strOldSub.length(),strNewSub);
		iStartPos = strSrc.find(strOldSub);
	}
	return strSrc;
}

//字符串转浮点型
 double  Calculate::stringToDouble(string strSur)
 {
	 if (strSur == "")
	 {
		 return CODE_STREMPTY;
	 }
	 double dTemp = atof(strSur.c_str());
	 return dTemp;
 }
 //浮点型数据转化为字符串
 string  Calculate::DoubleToString(double dData,int reserve)
 {
	 string strTemp ="";
	 stringstream strdou;
	 if (reserve < 0) //如果采用默认格式，则直接转化就行
	 {
		 strdou << dData;
		 strdou >> strTemp; //数值转化为字符串
		 return strTemp;
	 }	
	 char cTemp[50] = {0};
	 string strFramate = "%.f";
	 strFramate.insert(2,Dec2String(reserve));
	 sprintf(cTemp,strFramate.c_str(),dData);
	 strTemp = strTemp + cTemp;
	 return strTemp;
 }
 //产生0-1随机数
 float Calculate::genRandomData()
 {
	srand(time(NULL));//根据时间产生随机数据种子
	float fRes = rand()/(RAND_MAX - 0.0);
	return fRes;
 }
 //产生任意范围内随机数
 int Calculate::genRandomData(int min, int max)
 {
   int fRes = 0;
   srand(time(NULL));//根据时间产生随机数据种子
   if (min < max)
   {
	   fRes = rand()%(max - min + 1) + min;
   } 
   else
   {
	   fRes = rand()%(min - max + 1) + max;
   }   
   return fRes;
 }

 //快速对数组进行排序
 void Calculate::arraySort(int * arr,int length)
 {
	fastSort(arr,0,length - 1);//调用快速排序算法
 }
  //快速对数组进行排序
 void fastSort(int * arr,int left, int length)
 {
	 if (arr == NULL)
	 {
		 return;
	 }
	 if (left < length)
	 {
		 int iLeft = left;
		 int iRight = length;
		 int iKey = arr[iLeft];
		 while (iLeft < iRight)
		 {
			 //先从右网左进行搜索，查找比key值小的数,所以这里取等很重要
			 while (arr[iRight] >= iKey && iLeft < iRight)
			 {
				 iRight --;
			 }
			 arr[iLeft] = arr[iRight];
			 while (arr[iLeft] <= iKey && iLeft < iRight)
			 {
				 iLeft ++;
			 }
			 arr[iRight] = arr[iLeft];
		 }
		 arr[iLeft] = iKey;
		 //递归调用，先进行左边排序
		 fastSort(arr,left, iLeft-1);
		 //递归调用，先进行右边边排序
		 fastSort(arr,iRight + 1, length);
	 }
 }