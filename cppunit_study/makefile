modules:=money
 
LDPATH=-L .

module_path= .


prog1=obj1
prog2=obj2




all:$(prog1)  $(prog2)
	g++ -std=c++11  -o test ./money/Money.o  ./money_test/Money_Test.o ./money_test/Money_Test_Main.o	\
	-L /usr/local/lib -lcppunit -ldl -lstdc++
	
$(prog1):
	echo "-------------"
	make -C  $(module_path)/money -f Money.mak   module_object=money.o
$(prog2):
	make -C  $(module_path)/money_test -f Money_Test.mak  module_object=money_test.o

.PHONE: clean 
clean: 
	rm -rf ./money/*.o
	rm -rf ./money/*.d
	rm -rf ./money_test/*.o
	rm -rf ./money_test/*.d
