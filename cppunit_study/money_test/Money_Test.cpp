/************************************
Money_Test.cpp
5.28

****************************************/
#include "Money_Test.h"
#include "Money.h"
#include <string>

using namespace std;

/* å°è¯¥TestSuiteæ³¨åå°åå­ä¸ºâalltestâçTestSuiteä¸­ï¼å¦ææªå®ä¹ä¼èªå¨å®ä¹ï¼ä¹å¯ä»¥ä½¿ç¨CPPUNIT_TEST_SUITE_REGISTRATION( MathTest );å®ä¹å°å¨å±æªå½åçTestSuiteä¸­ */

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(CMoneyTest,"alltest");

/*åå§åå¨ä½*/
void CMoneyTest::setUp()
{

}

/*æ¸é¤å¨ä½*/
void CMoneyTest::tearDown()
{

}

/*ç¼åæµè¯ç¨ä¾ï¼
æ­¤å¤ç¼ååä¸ªç¨ä¾åå«æ¥æµè¯CMoneyç±»çåä¸ªæåå½æ°*/
/*test app in Money.cpp*/

/*test constructor*/
void CMoneyTest::testConstructor()
{
    double dNum = 22124.44;
    string sCurrency = "DD";
    CMoney MyMoney(dNum, sCurrency);

    CPPUNIT_ASSERT_EQUAL(dNum, MyMoney.GetAmount());
    CPPUNIT_ASSERT_EQUAL(sCurrency, MyMoney.GetCurrency());

}


/*test operator ==()*/
void CMoneyTest::testOptorEqual()
{
    // Set up
    const CMoney money123FF( 123, "FF" );
    const CMoney money123USD( 123, "USD" );
    const CMoney money12FF( 12, "FF" );
    const CMoney money12USD( 12, "USD" );

    // Process & Check
    CPPUNIT_ASSERT(money123FF == money123FF);    // ==
    CPPUNIT_ASSERT(!(money12FF == money123FF));     // != amount
    CPPUNIT_ASSERT(!(money123USD == money123FF));   // != currency
    CPPUNIT_ASSERT(!(money12USD == money123FF));   
// != currency and != amount

}

/*test operator!=()*/
void CMoneyTest::testOptorNotEqual()
{
    // Set up
    const CMoney money123FF( 123, "FF" );
    const CMoney money123USD( 123, "USD" );
    const CMoney money12FF( 12, "FF" );
    const CMoney money12USD( 12, "USD" );

    // Process & Check
    CPPUNIT_ASSERT(!(money123FF != money123FF));    // ==
    CPPUNIT_ASSERT(money12FF != money123FF);     // != amount
    CPPUNIT_ASSERT(money123USD != money123FF);   // != currency
    CPPUNIT_ASSERT(money12USD != money123FF);    
// != currency and != amount

}

/*test operator+=()*/
void CMoneyTest::testOptorAdd()
{
  // Set up
  const CMoney money12FF( 12, "FF" );
  const CMoney expectedMoney( 135, "FF" );

  // Process
  CMoney money( 123, "FF" );
  money += money12FF;

  // Check
  CPPUNIT_ASSERT( expectedMoney !=  money );           // add works
}

