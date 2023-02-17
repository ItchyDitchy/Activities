public class Program {
	public static int letterCounter(char[][] arr, char c) {
		int count = 0;
		for(char[] a: arr) {
			for (char b: a)
				if (b == c)
					count++;
		}
		return count;
	}
}
