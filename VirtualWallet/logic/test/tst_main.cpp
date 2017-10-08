#include <QString>
#include <QtTest>

class TestClassA : public QObject
{
   Q_OBJECT
public:
   TestClassA();



private Q_SLOTS:
   void testCase1();

};

class TestClassB : public QObject
{
   Q_OBJECT
public:
   TestClassB();



private Q_SLOTS:
   void testCase2();
};

void TestClassA::testCase1()
{
   // Define test here.
}

void TestClassB::testCase2()
{
   // Define test here.
}

// Additional tests defined here.

// Note: This is equivalent to QTEST_APPLESS_MAIN for multiple test classes.
int main(int argc, char** argv)
{
   int status = 0;
   {
      TestClassA tc;
      status |= QTest::qExec(&tc, argc, argv);
   }
   {
      TestClassB tc;
      status |= QTest::qExec(&tc, argc, argv);
   }
   return status;
}
