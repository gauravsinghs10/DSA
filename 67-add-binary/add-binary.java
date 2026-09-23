class Solution {
    public String addBinary(String a, String b) {
        StringBuilder sb = new StringBuilder();
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        // Jab tak strings bachi hain ya carry bacha hai
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            if (i >= 0) {
                sum += a.charAt(i) - '0'; // Char to Int conversion
                i--;
            }
            if (j >= 0) {
                sum += b.charAt(j) - '0';
                j--;
            }

            sb.append(sum % 2); // Binary bit (0 ya 1) append karo
            carry = sum / 2;    // Carry calculate karo (1 ya 0)
        }

        // String ko reverse karke return karo
        return sb.reverse().toString();
    }
}