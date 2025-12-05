class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        
        // P1: Crear una copia y ordenarla.
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());

        // P2: Definir punteros.
        // j final pequeños
        // k final grandes
        int mid = (n + 1) / 2;
        int j = mid - 1; 
        int k = n - 1;   

        // P3: Intercalar en el arreglo original
  
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                nums[i] = sorted[j--]; // Posición par (0, 2, 4...) -> valle
            } else {
                nums[i] = sorted[k--]; // Posición impar (1, 3, 5...) -> pico
            }
        }
    }
};