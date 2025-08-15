#include "CommonLibrary.h"

Calculate::Calculate()
{
}
Calculate::~Calculate()
{
}
//ע��������static�Ͳ�����д��
Calculate & Calculate::getInstance()
{
	static Calculate instance;
	return instance;
}

//�ַ����ָ����ʵ��
int Calculate::stringToSeperate(string strSrc, string strSpeator, vector<string>& strVect)
{
	int iStart = 0;
	int iEnd = 0;
	string strTemp = "";
	if(strSrc.size() == 0 || strSpeator.size() == 0 )
	{
		return CODE_STREMPTY;//ԭ��Ϊ���򷵻�0
	}
	if(strSrc.find(strSpeator) == string::npos)
	{//ֻ��һ���ֶ�
		strVect.push_back(strSrc);
		return 1;
	}
	//�ж���ֶε�ʱ��
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
			iStart = iEnd + strSpeator.size();//������ʼλ
		}
	}
	return strVect.size();
}

//�ַ���ת��Ϊ��ֵ
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

//�ַ���ȫ��ת��Ϊ��д
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
//�ַ���ȫ��ת��ΪСд
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

//��ʮ���Ƶ�����ת��Ϊ�ַ���
string  Calculate::Dec2String(int decimal)
{
	string strTemp = "";
	char cTemp[50] = {0};
	sprintf(cTemp,"%d",decimal);
	strTemp = strTemp + cTemp;
	return strTemp;
}

//��ʮ�����Ƶ�����ת��Ϊ�ַ���
string  Calculate::Hex2String(long hex)
{
	string strTemp = "";
	char cTemp[50] = {0};
	sprintf(cTemp,"%X",hex);
	strTemp = strTemp + cTemp;
	return strTemp;
}
//ɾ�����ַ���
string Calculate::toDelteSubStr(string strSrc,string strSub)
{
	int iStart = 0;
	if (strSrc == "" || strSub == "")
	{//���ԭ�����Ӵ�Ϊ���򷵻�ԭ��
		return strSrc;
	}
	iStart = strSrc.find(strSub,0);
	if (iStart == string::npos)
	{//������������������ַ������򷵻�ԭ������
		return strSrc;
	}
	while (iStart != string::npos)
	{
		strSrc = strSrc.erase(iStart,strSub.length());
		iStart = strSrc.find(strSub,0);
	}
	return strSrc;
}
//�滻һ���ַ����������Ӵ�
string  Calculate::String2ReplaceSubStr_All(string strSrc,string strOldSub, string strNewSub)
{
	int iStartPos = 0;//���Ӵ�����ʼλ��
	if (strSrc == "" || strOldSub == "" || strNewSub == "" || strOldSub == strNewSub)
	{//����������滻���´���ԭ�Ӵ�һ���Ĵ������������������ѭ��
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

//�ַ���ת������
 double  Calculate::stringToDouble(string strSur)
 {
	 if (strSur == "")
	 {
		 return CODE_STREMPTY;
	 }
	 double dTemp = atof(strSur.c_str());
	 return dTemp;
 }
 //����������ת��Ϊ�ַ���
 string  Calculate::DoubleToString(double dData,int reserve)
 {
	 string strTemp ="";
	 stringstream strdou;
	 if (reserve < 0) //�������Ĭ�ϸ�ʽ����ֱ��ת������
	 {
		 strdou << dData;
		 strdou >> strTemp; //��ֵת��Ϊ�ַ���
		 return strTemp;
	 }	
	 char cTemp[50] = {0};
	 string strFramate = "%.f";
	 strFramate.insert(2,Dec2String(reserve));
	 sprintf(cTemp,strFramate.c_str(),dData);
	 strTemp = strTemp + cTemp;
	 return strTemp;
 }
 //����0-1�����
 float Calculate::genRandomData()
 {
	srand(time(NULL));//����ʱ����������������
	float fRes = rand()/(RAND_MAX - 0.0);
	return fRes;
 }
 //�������ⷶΧ�������
 int Calculate::genRandomData(int min, int max)
 {
   int fRes = 0;
   srand(time(NULL));//����ʱ����������������
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

 //���ٶ������������
 void Calculate::arraySort(int * arr,int length)
 {
	fastSort(arr,0,length - 1);//���ÿ��������㷨
 }
  //���ٶ������������
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
			 //�ȴ�������������������ұ�keyֵС����,��������ȡ�Ⱥ���Ҫ
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
		 //�ݹ���ã��Ƚ����������
		 fastSort(arr,left, iLeft-1);
		 //�ݹ���ã��Ƚ����ұ߱�����
		 fastSort(arr,iRight + 1, length);
	 }
 }