CC=g++
CC+= -std=c++11

src_dir= .

include_dir= -I $(src_dir)  -I /usr/include/cppuint

sources:=$(wildcard $(src_dir)/*.cpp) 

objects:=$(patsubst %.cpp,%.o,$(sources))

dependence:=$(objects:.o=.d)

$(module_object): $(objects)	


%.o: %.cpp
	$(CC) $(CPPFLAGS)  $(include_dir) -c $< -o $@

%.d: %.cpp
	set -e; rm -f $@; \
        $(CC) -MM $(include_dir) $(CPPFLAGS) $< > $@.$$$$; \
        #sed 's,.o[ ]*:,.o $@ : ,g' < $@.$$$$ > $@; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
        rm -f $@.$$$$


.PHONY: clean
clean:	#.$$已在每次使用后立即删除。-f参数表示被删文件不存在时不报错
	rm -f all $(objects) $(dependence)

echo:	#调试时显示一些变量的值
	@echo sources=$(sources)
	@echo objects=$(objects)
	@echo dependence=$(dependence)
	@echo CPPFLAGS=$(CPPFLAGS)

-include $(dependence)

