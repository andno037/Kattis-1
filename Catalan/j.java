import java.math.BigInteger;
import java.util.Scanner;


public class j {

	public static BigInteger[] cat;
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int q,n;
		q = in.nextInt();
		cat = new BigInteger[5010];
		cat[0] = BigInteger.ONE;
		cat[1] = BigInteger.ONE;
		while (q > 0){
			q--;
			n = in.nextInt();
			System.out.println(catalan(n));
		}		
	}
	
	private static BigInteger catalan(int n){		
		if (cat[n] != null) return cat[n];
		BigInteger c = BigInteger.valueOf(4*n-2).multiply(catalan(n-1)).divide(BigInteger.valueOf(n+1));
		return cat[n] = c;		
	}
}
