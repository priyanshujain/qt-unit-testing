#include <QtTest>
#include <QtCore>


class testDate: public QObject
{
     Q_OBJECT
 private slots:
     void testSkip_data();
     void testSkip();
 };


 void testDate::testSkip_data()
 {
     QTest::addColumn<int>("val1");
     QTest::addColumn<int>("val2");

     QTest::newRow("1") << 1 << 1;
     QTest::newRow("2") << 1 << 2;
     QTest::newRow("3") << 3 << 3;
     QTest::newRow("5") << 5 << 5;
     QTest::newRow("4") << 4 << 5;
 }

 void testDate::testSkip()
 {
     QFETCH(int, val1);
     QFETCH(int, val2);

     if ( val2 == 2 )
         QSKIP("Two isn't good, not doing it", SkipSingle);
     if ( val1 == 5 )
         QSKIP("Five! I've had enough, bailing here", SkipAll);
     QCOMPARE( val1, val2 );
 }

 QTEST_MAIN(testDate)
 #include "tutorial4.moc"
