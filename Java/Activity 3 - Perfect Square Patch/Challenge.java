public class Challenge {
	public static int[][] squarePatch(int n) {
		int [][]ar = new int [n][n];
		for (int[] row : ar)
			java.util.Arrays.fill(row, n);
		return ar;
	}
}
