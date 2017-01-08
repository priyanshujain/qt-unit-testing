#include <QtTest>
#include <QtCore>


class testDate: public QObject
{
     Q_OBJECT
 private slots:
     void testUnexpectedPass();
 };

 void testDate::testUnexpectedPass()
 {
     QEXPECT_FAIL("", "1 is not 2, even for very large 1", Continue);
     QCOMPARE( 1, 1 );
     QCOMPARE( 2, 2 );

     QEXPECT_FAIL("", "1 is not 2, even for very small 2", Abort);
     QCOMPARE( 1, 1 );
     QCOMPARE( 3, 3 );
 }

 QTEST_MAIN(testDate)
 #include "tutorial4c.moc"
