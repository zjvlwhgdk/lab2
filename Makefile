# 기본 목표: 실행 파일 생성
all: dtest

# 공유 라이브러리 생성
lib/libmath.so: lib/sum.o lib/minus.o lib/multiply.o lib/divide.o
	gcc -shared -o lib/libmath.so lib/sum.o lib/minus.o lib/multiply.o lib/divide.o

# 개별 목적 파일 생성 규칙
lib/sum.o: lib/sum.c lib/math.h
	gcc -fPIC -c lib/sum.c -o lib/sum.o

lib/minus.o: lib/minus.c lib/math.h
	gcc -fPIC -c lib/minus.c -o lib/minus.o

lib/multiply.o: lib/multiply.c lib/math.h
	gcc -fPIC -c lib/multiply.c -o lib/multiply.o

lib/divide.o: lib/divide.c lib/math.h
	gcc -fPIC -c lib/divide.c -o lib/divide.o

# dtest 실행 파일 생성
dtest: dtest.c lib/libmath.so
	gcc -rdynamic dtest.c -Llib -lmath -ldl -o dtest

# 정리 규칙
clean:
	rm -f lib/*.o lib/libmath.so dtest

# 실행 규칙
run: dtest
	./dtest


