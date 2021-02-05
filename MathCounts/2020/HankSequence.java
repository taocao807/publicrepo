import java.util.*;

class HankSequence
{
    public static void main(String[] args) {

        int base = 10;
        int n = 729;
        int M = 0;
        boolean subtract = false;
        int start = 1;

        if (args != null && args.length > 0) {
            for (int i = 0; i < args.length; ++i)
            {
                if (args[i].compareTo("-upper") == 0 && i < args.length - 1) {
                    n = Integer.parseInt(args[i+1]);
                }
                else if (args[i].compareTo("-base") == 0 && i < args.length - 1)
                {
                    base = Integer.parseInt(args[i+1]);
                }
                else if (args[i].compareTo("-check") == 0 && i < args.length -1)
                {
                    M = Integer.parseInt(args[i+1]);
                }
                else if (args[i].compareTo("-subtract") == 0) {
                    subtract = true;
                }
                else if (args[i].compareTo("-start") == 0 && i < args.length - 1)
                {
                    start = Integer.parseInt(args[i+1]);
                }
            }
        }

        HankSequence h = new HankSequence();

        ArrayList<Integer> result = h.BuildHankSequence(start, n, M);

        if (M > 0) return;

        System.out.println("There are " + result.size() + " terms:");

        for (int i = 0; i < result.size(); i++)
        {
            if (i % 8 == 0 && i != 0) System.out.println();
            int x = subtract ? result.get(i) - 1 : result.get(i);
            String numberAsString = Integer.toString(x, base);
            String s = base == 10? "        ".substring(numberAsString.length()) + numberAsString : "000000".substring(numberAsString.length()) + numberAsString;
            System.out.print(s + " ");
        }
    }

    ArrayList<Integer> BuildHankSequence(int start, int n, int M)
    {
        ArrayList<Integer> result = new ArrayList();
        result.add(start);
        result.add(start+1);

        for (int i = start + 2; i < n; i++)
        {
            boolean canAdd = IsValidNextNumber(i, M, result);
            if (canAdd) {
                result.add(i);
            }
        }

        return result;
    }

    boolean IsValidNextNumber(int n, int M, ArrayList<Integer> result)
    {
        for (int i = result.size()-1; i >= 0; i--)
        {
            int diff = n - result.get(i);
            for (int j=0; j < i; j++)
            {
                if (result.get(i) - result.get(j) == diff)
                {
                    if (M == n)
                    {
                        System.out.print(result.get(j) + ", " + result.get(i) + ", and " + n + " form an arithmetic sequence.");
                    }
                    
                    return false;
                }
            }
        }
    
    return true;
    }
}