#include "stdafx.h"
#include "CppUnitTest.h"
#include "../PortableElmax/Elmax.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestElmax
{
	TEST_CLASS(UnitTestSaveAndRead)
	{
	private:

		TSTR GetFolderPath()
		{
			return _TS("c:\\temp\\");
		}

	public:
		
		TEST_METHOD(SaveReadRootName)
		{
			using namespace Elmax;
			Element root(_TS("aa"));

			TSTR rootName = _TS("aa");
			Element elem = root[_TS("bb")][_TS("cc")].CreateNew();
			bool dd = true;
			Assert::IsTrue(elem.Exists());
			elem[_TS("dd")].SetBool(dd);

			Assert::IsTrue(rootName == elem.GetRootName());

			TSTR file = GetFolderPath() + _TS("SaveReadRootName.xml");
			root.Save(file, FT_UTF8);

			Element root2;
			root2.Open(file);
			//root2.Save(GetFolderPath() + _TS("SaveReadRootNameCheck.xml"), FT_UTF8);

			Element elem2 = root2[_TS("aa")][_TS("bb")][_TS("cc")];
			Assert::IsTrue(elem2.Exists());

			bool dd2 = elem2[_TS("dd")].GetBool(false);

			Assert::AreEqual(dd, dd2);

			Assert::IsTrue(rootName == elem2.GetRootName());
			root.Destroy();
			root2.Destroy();
		}
		TEST_METHOD(SaveReadDateTime)
		{
			using namespace Elmax;
			Element root(_TS("aa"));

			Element elem = root[_TS("bb")][_TS("cc")].CreateNew();
			DateAndTime dd(2006, 7, 23, 9, 0, 23);
			Assert::IsTrue(elem.Exists());
			elem[_TS("dd")].SetDateTime(dd);
			DateAndTime ddcheck;
			DateAndTime dd3 = elem[_TS("dd")].GetDateTime(ddcheck);

			Assert::AreEqual(dd.GetYear(), dd3.GetYear());
			Assert::AreEqual(dd.GetMonth(), dd3.GetMonth());
			Assert::AreEqual(dd.GetMonthDay(), dd3.GetMonthDay());
			Assert::AreEqual(dd.GetHour(), dd3.GetHour());
			Assert::AreEqual(dd.GetMinute(), dd3.GetMinute());
			Assert::AreEqual(dd.GetSecond(), dd3.GetSecond());

			TSTR file = GetFolderPath() + _TS("SaveReadDateTime.xml");
			root.Save(file, FT_UTF8);

			Element root2;
			root2.Open(file);
			//root2.Save(GetFolderPath() + _TS("SaveReadDateTimeCheck.xml"), FT_UTF8);

			Element elem2 = root2[_TS("aa")][_TS("bb")][_TS("cc")];
			Assert::IsTrue(elem2.Exists());

			DateAndTime dd2 = elem2[_TS("dd")].GetDateTime(ddcheck);

			Assert::AreEqual(dd.GetYear(), dd2.GetYear());
			Assert::AreEqual(dd.GetMonth(), dd2.GetMonth());
			Assert::AreEqual(dd.GetMonthDay(), dd2.GetMonthDay());
			Assert::AreEqual(dd.GetHour(), dd2.GetHour());
			Assert::AreEqual(dd.GetMinute(), dd2.GetMinute());
			Assert::AreEqual(dd.GetSecond(), dd2.GetSecond());
			root.Destroy();
			root2.Destroy();
		}
		TEST_METHOD(SaveReadDate)
		{
			using namespace Elmax;
			Element root(_TS("aa"));

			Element elem = root[_TS("bb")][_TS("cc")].CreateNew();
			Date dd(2010, 10, 1);
			Assert::IsTrue(elem.Exists());
			elem[_TS("dd")].SetDate(dd);
			Date ddcheck;
			Date dd3 = elem[_TS("dd")].GetDate(ddcheck);

			Assert::AreEqual(dd.GetYear(), dd3.GetYear());
			Assert::AreEqual(dd.GetMonth(), dd3.GetMonth());
			Assert::AreEqual(dd.GetMonthDay(), dd3.GetMonthDay());

			TSTR file = GetFolderPath() + _TS("SaveReadDate.xml");
			root.Save(file, FT_UTF8);

			Element root2;
			root2.Open(file);
			//root2.Save(GetFolderPath() + _TS("SaveReadDateCheck.xml"), FT_UTF8);

			Element elem2 = root2[_TS("aa")][_TS("bb")][_TS("cc")];
			Assert::IsTrue(elem2.Exists());

			Date dd2 = elem2[_TS("dd")].GetDate(ddcheck);

			Assert::AreEqual(dd.GetYear(), dd2.GetYear());
			Assert::AreEqual(dd.GetMonth(), dd2.GetMonth());
			Assert::AreEqual(dd.GetMonthDay(), dd2.GetMonthDay());
			root.Destroy();
			root2.Destroy();
		}
		TEST_METHOD(SaveReadBoolean)
		{
			using namespace Elmax;
			Element root(_TS("aa"));

			Element elem = root[_TS("bb")][_TS("cc")].CreateNew();
			bool dd = true;
			Assert::IsTrue(elem.Exists());
			elem[_TS("dd")].SetBool(dd);

			TSTR file = GetFolderPath() + _TS("SaveReadBoolean.xml");
			root.Save(file, FT_UTF8);

			Element root2;
			root2.Open(file);
			//root2.Save(GetFolderPath() + _TS("SaveReadBooleanCheck.xml"), FT_UTF8);

			Element elem2 = root2[_TS("aa")][_TS("bb")][_TS("cc")];
			Assert::IsTrue(elem2.Exists());

			bool dd2 = elem2[_TS("dd")].GetBool(false);

			Assert::AreEqual(dd, dd2);
			root.Destroy();
			root2.Destroy();
		}
		TEST_METHOD(SaveReadProcessingInstruction)
		{
			using namespace Elmax;
			Element root(_TS("aa"));

			Element elem = root[_TS("bb")][_TS("cc")].CreateNew();
			bool dd = true;
			Assert::IsTrue(elem.Exists());
			elem[_TS("dd")].SetBool(dd);

			TSTR file = GetFolderPath() + _TS("SaveReadProcessingInstruction.xml");
			root.Save(file, FT_UTF8);

			Element root2;
			std::map<TSTR, TSTR> prep;;
			root2.Open(prep, file);
			//root2.Save(GetFolderPath() + _TS("SaveReadProcessingInstructionCheck.xml"), FT_UTF8);

			Assert::IsTrue(prep[_TS("version")] == TSTR(_TS("1.0")));
			Assert::IsTrue(prep[_TS("encoding")] == TSTR(_TS("UTF-8")));
			
			Element elem2 = root2[_TS("aa")][_TS("bb")][_TS("cc")];
			Assert::IsTrue(elem2.Exists());

			bool dd2 = elem2[_TS("dd")].GetBool(false);

			Assert::AreEqual(dd, dd2);
			root.Destroy();
			root2.Destroy();
		}
		TEST_METHOD(SaveReadInt64)
		{
			using namespace Elmax;
			Element root(_TS("aa"));

			Element elem = root[_TS("bb")][_TS("cc")].CreateNew();
			ELMAX_INT64 dd = 14000000000L;
			Assert::IsTrue(elem.Exists());
			elem[_TS("dd")].SetInt64(dd);

			TSTR file = GetFolderPath() + _TS("SaveReadInt64.xml");
			root.Save(file, FT_UTF8);

			Element root2;
			root2.Open(file);
			//root2.Save(GetFolderPath() + _TS("SaveReadInt64Check.xml"), FT_UTF8);

			Element elem2 = root2[_TS("aa")][_TS("bb")][_TS("cc")];
			Assert::IsTrue(elem2.Exists());

			ELMAX_INT64 dd2 = elem2[_TS("dd")].GetInt64(10);

			Assert::IsTrue(dd == dd2);
			root.Destroy();
			root2.Destroy();
		}
		TEST_METHOD(SaveReadInt)
		{
			using namespace Elmax;
			Element root(_TS("aa"));

			Element elem = root[_TS("bb")][_TS("cc")].CreateNew();
			int dd = 2000000000;
			Assert::IsTrue(elem.Exists());
			elem[_TS("dd")].SetInt32(dd);

			TSTR file = GetFolderPath() + _TS("SaveReadIntSaveReadInt.xml");
			root.Save(file, FT_UTF8);

			Element root2;
			root2.Open(file);
			//root2.Save(GetFolderPath() + _TS("SaveReadIntCheck.xml"), FT_UTF8);

			Element elem2 = root2[_TS("aa")][_TS("bb")][_TS("cc")];
			Assert::IsTrue(elem2.Exists());

			int dd2 = elem2[_TS("dd")].GetInt32(10);

			Assert::AreEqual(dd, dd2);
			root.Destroy();
			root2.Destroy();
		}
		TEST_METHOD(SaveReadShort)
		{
			using namespace Elmax;
			Element root(_TS("aa"));

			Element elem = root[_TS("bb")][_TS("cc")].CreateNew();
			short dd = 32000;
			Assert::IsTrue(elem.Exists());
			elem[_TS("dd")].SetInt16(dd);

			TSTR file = GetFolderPath() + _TS("SaveReadShort.xml");
			root.Save(file, FT_UTF8);

			Element root2;
			root2.Open(file);
			//root2.Save(GetFolderPath() + _TS("SaveReadShortCheck.xml"), FT_UTF8);

			Element elem2 = root2[_TS("aa")][_TS("bb")][_TS("cc")];
			Assert::IsTrue(elem2.Exists());

			short dd2 = elem2[_TS("dd")].GetInt16(10);

			Assert::AreEqual(dd, dd2);
			root.Destroy();
			root2.Destroy();
		}
		TEST_METHOD(SaveReadChar)
		{
			using namespace Elmax;
			Element root(_TS("aa"));

			Element elem = root[_TS("bb")][_TS("cc")].CreateNew();
			char dd = 'A';
			Assert::IsTrue(elem.Exists());
			elem[_TS("dd")].SetChar(dd);

			TSTR file = GetFolderPath() + _TS("SaveReadChar.xml");
			root.Save(file, FT_UTF8);

			Element root2;
			root2.Open(file);
			//root2.Save(GetFolderPath() + _TS("SaveReadCharCheck.xml"), FT_UTF8);

			Element elem2 = root2[_TS("aa")][_TS("bb")][_TS("cc")];
			Assert::IsTrue(elem2.Exists());

			char dd2 = elem2[_TS("dd")].GetChar('P');

			Assert::AreEqual(dd, dd2);
			root.Destroy();
			root2.Destroy();
		}
		TEST_METHOD(SaveReadUInt64)
		{
			using namespace Elmax;
			Element root(_TS("aa"));

			Element elem = root[_TS("bb")][_TS("cc")].CreateNew();
			unsigned ELMAX_INT64 dd = 14000000000UL;
			Assert::IsTrue(elem.Exists());
			elem[_TS("dd")].SetUInt64(dd);

			TSTR file = GetFolderPath() + _TS("SaveReadUInt64.xml");
			root.Save(file, FT_UTF8);

			Element root2;
			root2.Open(file);
			//root2.Save(GetFolderPath() + _TS("SaveReadUInt64Check.xml"), FT_UTF8);

			Element elem2 = root2[_TS("aa")][_TS("bb")][_TS("cc")];
			Assert::IsTrue(elem2.Exists());

			unsigned ELMAX_INT64 dd2 = elem2[_TS("dd")].GetUInt64(10);

			Assert::AreEqual(dd, dd2);
			root.Destroy();
			root2.Destroy();
		}
		TEST_METHOD(SaveReadUInt)
		{
			using namespace Elmax;
			Element root(_TS("aa"));

			Element elem = root[_TS("bb")][_TS("cc")].CreateNew();
			unsigned int dd = 4000000000;
			Assert::IsTrue(elem.Exists());
			elem[_TS("dd")].SetUInt32(dd);

			TSTR file = GetFolderPath() + _TS("SaveReadUInt.xml");
			root.Save(file, FT_UTF8);

			Element root2;
			root2.Open(file);
			//root2.Save(GetFolderPath() + _TS("SaveReadUIntCheck.xml"), FT_UTF8);

			Element elem2 = root2[_TS("aa")][_TS("bb")][_TS("cc")];
			Assert::IsTrue(elem2.Exists());

			unsigned int dd2 = elem2[_TS("dd")].GetUInt32(10);

			Assert::AreEqual(dd, dd2);
			root.Destroy();
			root2.Destroy();
		}
		TEST_METHOD(SaveReadUShort)
		{
			using namespace Elmax;
			Element root(_TS("aa"));

			Element elem = root[_TS("bb")][_TS("cc")].CreateNew();
			unsigned short dd = 65000;
			Assert::IsTrue(elem.Exists());
			elem[_TS("dd")].SetUInt16(dd);

			TSTR file = GetFolderPath() + _TS("SaveReadUShort.xml");
			root.Save(file, FT_UTF8);

			Element root2;
			root2.Open(file);
			//root2.Save(GetFolderPath() + _TS("SaveReadUShortCheck.xml"), FT_UTF8);

			Element elem2 = root2[_TS("aa")][_TS("bb")][_TS("cc")];
			Assert::IsTrue(elem2.Exists());

			unsigned short dd2 = elem2[_TS("dd")].GetUInt16(10);

			Assert::IsTrue(dd == dd2);
			root.Destroy();
			root2.Destroy();
		}
		TEST_METHOD(SaveReadUChar)
		{
			using namespace Elmax;
			Element root(_TS("aa"));

			Element elem = root[_TS("bb")][_TS("cc")].CreateNew();
			unsigned char dd = 255;
			Assert::IsTrue(elem.Exists());
			elem[_TS("dd")].SetUChar(dd);

			TSTR file = GetFolderPath() + _TS("SaveReadUChar.xml");
			root.Save(file, FT_UTF8);

			Element root2;
			root2.Open(file);
			//root2.Save(GetFolderPath() + _TS("SaveReadUCharCheck.xml"), FT_UTF8);

			Element elem2 = root2[_TS("aa")][_TS("bb")][_TS("cc")];
			Assert::IsTrue(elem2.Exists());

			unsigned char dd2 = elem2[_TS("dd")].GetUChar(12);

			Assert::AreEqual(dd, dd2);
			root.Destroy();
			root2.Destroy();
		}
		TEST_METHOD(SaveReadString)
		{
			using namespace Elmax;
			Element root(_TS("aa"));

			Element elem = root[_TS("bb")][_TS("cc")].CreateNew();
			TSTR dd = _TS("ABCD");
			Assert::IsTrue(elem.Exists());
			elem[_TS("dd")].SetString(dd);

			TSTR dd3 = elem[_TS("dd")].GetString(_TS("A"));

			Assert::IsTrue(dd == dd3);

			TSTR file = GetFolderPath() + _TS("SaveReadString.xml");
			root.Save(file, FT_UTF8);

			Element root2;
			root2.Open(file);
			//root2.Save(GetFolderPath() + _TS("SaveReadStringCheck.xml"), FT_UTF8);

			Element elem2 = root2[_TS("aa")][_TS("bb")][_TS("cc")];
			Assert::IsTrue(elem2.Exists());

			TSTR dd2 = elem2[_TS("dd")].GetString(_TS("A"));

			Assert::IsTrue(dd == dd2);
			root.Destroy();
			root2.Destroy();
		}
		TEST_METHOD(SaveReadEscapeString)
		{
			using namespace Elmax;
			Element root(_TS("aa"));

			Element elem = root[_TS("bb")][_TS("cc")].CreateNew();
			TSTR dd = _TS("<ABCD>");
			Assert::IsTrue(elem.Exists());
			elem[_TS("dd")].SetString(dd);

			TSTR dd3 = elem[_TS("dd")].GetString(_TS("A"));

			Assert::IsTrue(dd == dd3);

			TSTR file = GetFolderPath() + _TS("SaveReadEscapeString.xml");
			root.Save(file, FT_UTF8);

			Element root2;
			root2.Open(file);
			//root2.Save(GetFolderPath() + _TS("SaveReadStringCheck.xml"), FT_UTF8);

			Element elem2 = root2[_TS("aa")][_TS("bb")][_TS("cc")];
			Assert::IsTrue(elem2.Exists());

			TSTR dd2 = elem2[_TS("dd")].GetString(_TS("A"));

			Assert::IsTrue(dd == dd2);
			root.Destroy();
			root2.Destroy();
		}
		TEST_METHOD(SaveReadDouble)
		{
			using namespace Elmax;
			Element root(_TS("aa"));

			Element elem = root[_TS("bb")][_TS("cc")].CreateNew();
			double dd = 123.0;
			Assert::IsTrue(elem.Exists());
			elem[_TS("dd")].SetDouble(dd);

			TSTR file = GetFolderPath() + _TS("SaveReadDouble.xml");
			root.Save(file, FT_UTF8);

			Element root2;
			root2.Open(file);
			//root2.Save(GetFolderPath() + _TS("SaveReadDoubleCheck.xml"), FT_UTF8);

			Element elem2 = root2[_TS("aa")][_TS("bb")][_TS("cc")];
			Assert::IsTrue(elem2.Exists());

			double dd2 = elem2[_TS("dd")].GetDouble(10.0);

			Assert::AreEqual(dd, dd2);
			root.Destroy();
			root2.Destroy();
		}
		TEST_METHOD(SaveReadFloat)
		{
			using namespace Elmax;
			Element root(_TS("aa"));

			Element elem = root[_TS("bb")][_TS("cc")].CreateNew();
			float dd = 123.0f;
			Assert::IsTrue(elem.Exists());
			elem[_TS("dd")].SetFloat(dd);

			TSTR file = GetFolderPath() + _TS("SaveReadFloat.xml");
			root.Save(file, FT_UTF8);

			Element root2;
			root2.Open(file);
			//root2.Save(GetFolderPath() + _TS("SaveReadFloatCheck.xml"), FT_UTF8);

			Element elem2 = root2[_TS("aa")][_TS("bb")][_TS("cc")];
			Assert::IsTrue(elem2.Exists());

			float dd2 = elem2[_TS("dd")].GetFloat(10.0f);

			Assert::AreEqual(dd, dd2);
			root.Destroy();
			root2.Destroy();
		}
		TEST_METHOD(SaveReadHex)
		{
			using namespace Elmax;
			Element root(_TS("aa"));

			Element elem = root[_TS("bb")][_TS("cc")].CreateNew();
			unsigned int dd = 0xACAC;
			Assert::IsTrue(elem.Exists());
			elem[_TS("dd")].SetHex(dd);

			unsigned int ans = elem[_TS("dd")].ReadHex(0xee);

			Assert::AreEqual(dd, ans);

			TSTR file = GetFolderPath() + _TS("SaveReadHex.xml");
			root.Save(file, FT_UTF8);

			Element root2;
			root2.Open(file);
			//root2.Save(GetFolderPath() + _TS("SaveReadHexCheck.xml"), FT_UTF8);

			Element elem2 = root2[_TS("aa")][_TS("bb")][_TS("cc")];
			Assert::IsTrue(elem2.Exists());

			unsigned int dd2 = elem2[_TS("dd")].ReadHex(0xee);

			Assert::AreEqual(dd, dd2);
			root.Destroy();
			root2.Destroy();
		}
		TEST_METHOD(SaveReadHexWithPrefix)
		{
			using namespace Elmax;
			Element root(_TS("aa"));

			Element elem = root[_TS("bb")][_TS("cc")].CreateNew();
			unsigned int dd = 0xACAC;
			Assert::IsTrue(elem.Exists());
			elem[_TS("dd")].SetHex(dd, true);

			unsigned int ans = elem[_TS("dd")].ReadHex(0xee);
			Assert::AreEqual(dd, ans);

			TSTR strAns = elem[_TS("dd")].GetString(_TS("0xee"));

			Assert::IsTrue(TSTR(_TS("0xACAC")) == strAns);

			TSTR file = GetFolderPath() + _TS("SaveReadHexWithPrefix.xml");
			root.Save(file, FT_UTF8);

			Element root2;
			root2.Open(file);
			//root2.Save(GetFolderPath() + _TS("SaveReadHexWithPrefixCheck.xml"), FT_UTF8);

			Element elem2 = root2[_TS("aa")][_TS("bb")][_TS("cc")];
			Assert::IsTrue(elem2.Exists());

			unsigned int dd2 = elem2[_TS("dd")].ReadHex(0xee);

			Assert::AreEqual(dd, dd2);
			root.Destroy();
			root2.Destroy();
		}
		TEST_METHOD(SaveReadHexWithLowerCase)
		{
			using namespace Elmax;
			Element root(_TS("aa"));

			Element elem = root[_TS("bb")][_TS("cc")].CreateNew();
			unsigned int dd = 0xACAC;
			Assert::IsTrue(elem.Exists());
			elem[_TS("dd")].SetString(_TS("acac"));

			unsigned int ans = elem[_TS("dd")].ReadHex(0xee);

			Assert::AreEqual(dd, ans);

			TSTR file = GetFolderPath() + _TS("SaveReadHexWithLowerCase.xml");
			root.Save(file, FT_UTF8);

			Element root2;
			root2.Open(file);
			//root2.Save(GetFolderPath() + _TS("SaveReadHexWithLowerCaseCheck.xml"), FT_UTF8);

			Element elem2 = root2[_TS("aa")][_TS("bb")][_TS("cc")];
			Assert::IsTrue(elem2.Exists());

			unsigned int dd2 = elem2[_TS("dd")].ReadHex(0xee);

			Assert::AreEqual(dd, dd2);
			root.Destroy();
			root2.Destroy();
		}
	};
}