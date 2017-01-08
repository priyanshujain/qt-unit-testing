#include <QtTest>
#include <QtCore>


class testDate: public QObject
{
     Q_OBJECT
 private slots:
     void testExpectedFail();
 };

 void testDate::testExpectedFail()
 {
     QEXPECT_FAIL("", "1 is not 2, even for very large 1", Continue);
     QCOMPARE( 1, 2 );
     QCOMPARE( 2, 2 );

     QEXPECT_FAIL("", "1 is not 2, even for very small 2", Abort);
     QCOMPARE( 1, 2 );
     // The next line will not be run, because we Abort on previous failure
     QCOMPARE( 3, 3 );
 }

 QTEST_MAIN(testDate)
 #include "tutorial4b.moc"
