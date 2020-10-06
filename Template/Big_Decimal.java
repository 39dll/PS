import java.math.*; // BigDecimal 사용시 필요
public class Main {
   public static void main(String[] args) {
      BigDecimal a = new BigDecimal("0.12345"),
            b = new BigDecimal("1.2345e-1"),
            c = new BigDecimal(0.12345),
            d = new BigDecimal(12345),
            e = BigDecimal.valueOf(0.12345),
            f = BigDecimal.valueOf(12345);
      // 문자열, double, long값 혹은 valueOf 메서드로도 생성이 가능
      
      a.add(b);
      // a + b
      a.add(b).add(c);
      // (a + b) + c
      // 연산 순서는 앞에서부터 차례로 계산.
      
      a.subtract(b);
      // a - b

      a.multiply(b);
      // a * b
      
      a.remainder(b);
      // a % b
      
      a.divide(b);
      // a / b 
      
      a.divide(b, BigDecimal.ROUND_CEILING); // 올림
      a.divide(b, BigDecimal.ROUND_FLOOR); // 내림
      a.divide(b, BigDecimal.ROUND_UP); // 양수면 올림, 음수면 내림
      a.divide(b, BigDecimal.ROUND_DOWN); // 양수면 내림, 음수면 올림
      a.divide(b, BigDecimal.ROUND_HALF_UP); // 반올림
      // divide 연산 후 무한소수일때 올림 지정 안하면 예외발생
      
      a.setScale(6);
      // 소수점 밑으로 6자리까지로 제한
      // 이때 기존 소수점이 설정한 자릿수보다 많으면 예외 발생
      
      a.setScale(3, BigDecimal.ROUND_HALF_UP);
      // 반올림 모드 설정을 하면 예외 발생X,
      
      a.abs();
      // 절댓값
      
      a.pow(123);
      // a ^ 123, 지수는 int형식
      
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
      
      a.toString();
      // a를 문자열로 변환, 보통 그냥 a를 출력시 이 과정을 거쳐 출력됨
      // 필요에 따라(길이가 길어질 경우) 1.0e-n 형식으로 변환되어 출력
      
      a.toPlainString();
      // 1.0e-n 형식이 아닌 원래 형태 그대로 문자열로 변환.
      
      a.toBigInteger();
      // BigInteger 형식으로 변환
      
      BigDecimal one = BigDecimal.ONE;
      // 0, 1, 10 등 자주쓰는 상수값 
   }
}
