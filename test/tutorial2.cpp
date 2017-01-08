#include <QtTest>
#include <QtCore>


class testDate: public QObject
{
     Q_OBJECT
 private slots:
     void testValidity();
     void testMonth_data();
     void testMonth();
 };

 void testDate::testValidity()
 {
     // 12 March 1967
     QDate date( 1967, 3, 12 );
     QVERIFY( date.isValid() );
 }

 void testDate::testMonth_data()
  {
     QTest::addColumn<int>("year");  // the year we are testing
     QTest::addColumn<int>("month"); // the month we are testing
     QTest::addColumn<int>("day");   // the day we are testing
     QTest::addColumn<QString>("monthName");   // the name of the month

     QTest::newRow("1967/3/11") << 1967 << 3 << 11 << QString("March");
     QTest::newRow("1966/1/10") << 1966 << 1 << 10 << QString("January");
     QTest::newRow("1999/9/19") << 1999 << 9 << 19 << QString("September");
     // more rows of dates can go in here...
 }

 void testDate::testMonth()
 {
     QFETCH(int, year);
     QFETCH(int , month);
     QFETCH(int, day);
     QFETCH(QString, monthName);

     QDate date;
     date.setDate( year, month, day );
     QCOMPARE( date.month(), month );
     QCOMPARE( QDate::longMonthName(date.month()), monthName );
    //QTEST( QDate::longMonthName(date.month()), "monthName" );
 }


 QTEST_MAIN(testDate)
 #include "tutorial1.moc"
