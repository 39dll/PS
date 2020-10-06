import java.math.*; // BigInteger 사용시 필요
public class Main {
   public static void main(String[] args) {
      BigInteger a, b, c;
      a = new BigInteger("65535");
      b = new BigInteger("FFFF", 16);
      c = BigInteger.valueOf(65535L);
      // 매개변수로 문자열, 2,8,16진수 문자열(이 경우, 2번째 매개변수로 몇진수인지 표기)
      // 또는 BigInteger의 valueOf 메서드를 사용하여 long 값을 사용하여 초기화 가능.
      
      a.add(b);
      // a + b
      a.add(b).add(c);
      // (a + b) + c
      // 연산 순서는 앞에서부터 차례로 계산.
      
      a.subtract(b);
      // a - b

      a.multiply(b);
      // a * b
      
      a.divide(b);
      // a / b 
      // 몫만 반환
      
      a.remainder(b);
      // a % b
      // 나머지 반환
      
      a.abs();
      // 절댓값
      
      a.pow(123);
      // a^123 지수는 int값만 가능
      
      a.compareTo(b);
      // a > b 일때 1
      // a == b 일때 0
      // a < b 일때 -1
      
      a.equals(b);
      // a == b 인지 true / false
      
      a.min(b);
      // a, b중 최솟값
      
      a.max(b);
      // a, b중 최댓값
      
      a.gcd(b);
      // a랑 b의 최대공약수
      
      a.toString();
      // a를 String 타입으로 변환
      // 보통 그냥 a를 출력하려 하면 해당 메서드로 변환하여 출력
      // 매개변수로 int값을 넣으면, 해당 진법으로 변환하여 출력
      
      BigInteger one = BigInteger.ONE;
      // BigInteger에서  상수 1. 상수는 0, 1, 2, 10 4개 있음.
   }
}
