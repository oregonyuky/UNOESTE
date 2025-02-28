import java.util.Scanner;

public class Main
{
    // Time Complexity: O(n*m)
    public static void FindSubstrings(String str, String pattern) {
        System.out.println("Pattern [" + pattern + "] found at: ");
        for(int i = 0; i <= str.length()-pattern.length(); i++)
            if(str.startsWith(pattern, i)) System.out.printf("%d, ", i+1);
    }
    
    public static int[] computeLPS(String pattern) {
        int[] lps = new int[pattern.length()];
        lps[0] = 0;
        int i = 1, len = 0;
        while (i < pattern.length()) {
            if (pattern.charAt(i) == pattern.charAt(len)) lps[i++] = ++len;
            else if (len != 0) len = lps[len - 1];
            else lps[i++] = 0;
        }
        return lps;
    }
    
    // Time Complexity: O(n+m)
    public static void KMP(String str, String pattern) {
        int M = pattern.length(), N = str.length();
        int[] lps = computeLPS(pattern);
        
        System.out.println("Pattern [" + pattern + "] found at: ");
        int i = 0, j = 0, c = 0;
        while ((N - i) >= (M - j)) {
            if (pattern.charAt(j) == str.charAt(i)) { j++; i++; }
            if (j == M) {
                System.out.printf("%d, ", i+1 - M);
                j = lps[j - 1];
            }
            else if (i < N && pattern.charAt(j) != str.charAt(i)) {
                if (j != 0) j = lps[j - 1];
                else i++;
            }
        }
    }
    
    // Testcases:
    // unoeste frederico unoeste | oeste
    // aaaabb | aaabb
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String str = scanner.nextLine();
		String pattern = scanner.nextLine();
		System.out.println("\n\nNaive: ");
		FindSubstrings(str, pattern);
		System.out.println("\n\nKMP: ");
		KMP(str, pattern);
	}
}