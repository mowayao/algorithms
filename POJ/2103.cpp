

import java.util.*;
import java.math.*;

public class Main {
	public static BigInteger gcd(BigInteger a, BigInteger b){
		 if(b.equals(BigInteger.valueOf(0))) return a;
		 else return gcd(b,a.mod(b)); 
	}
	private static Scanner in;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BigInteger []num = new BigInteger[20];
		in = new Scanner(System.in);
		while(in.hasNextInt()){
			int n = in.nextInt();
			BigInteger fz = BigInteger.ZERO;
			BigInteger fm = BigInteger.ONE;
			BigInteger LCM,tmp;
			for(int i = 0; i < n; i++) {
				int k = in.nextInt();
				num[i] = BigInteger.valueOf(k);
				tmp = fm.gcd(num[i]);
				fm = fm.divide(tmp).multiply(num[i]);
			}
			
			for(int i = 1; i < (1<<n); i++) {
				int cnt = 0;
				LCM = BigInteger.ONE;
				for(int j = 0; j < n; j++) {
					if((i&(1<<j))>0) {
						tmp = num[j].gcd(LCM);
						LCM = LCM.divide(tmp).multiply(num[j]);
						cnt++;
					}
				}
				LCM = fm.divide(LCM);
				if((cnt&1)!=0) {
					fz = fz.add(LCM);
				}else{
					fz = fz.subtract(LCM);
				}
			}
			BigInteger GCD = gcd(fz,fm);
			fm = fm.divide(GCD);
			fz = fz.divide(GCD);
			System.out.println(fz);
			System.out.println(fm);
		}
	}
}