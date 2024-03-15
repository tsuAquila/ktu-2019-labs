class CmdLineArguments {
	public static void main(String[] args) {
		int n = args.length;
		int arr[] = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(args[i]);
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					int t = arr[j + 1];
					arr[j + 1] = arr[j];
					arr[j] = t;
				}
			}
		}
		System.out.print("Sorted Array is:\n\t");
		for (int i : arr) {
			System.out.print(i + "  ");
		}
		System.out.println();
	}
}
