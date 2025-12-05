class Solution {
public:
    // Función auxiliar que resuelve el problema lineal usando un Vector
    int robLinear(vector<int>& nums, int start, int end) {
        int n = end - start + 1; // Cantidad de casas en este rango
        
        if (n == 0) return 0;
        if (n == 1) return nums[start];

        // Creamos el vector para guardar los resultados
        vector<int> dp(n);

        // Caso base 1: Primera casa del rango
        dp[0] = nums[start];
        // Caso base 2: Segunda casa (elegimos la mayor entre la 1ra y 2da)
        dp[1] = max(nums[start], nums[start + 1]);

        // Llenamos el vector linealmente
        for (int i = 2; i < n; i++) {
            // Decisión: ¿Me quedo con lo de la casa anterior (i-1)?
            // ¿O sumo la actual + lo de hace dos casas (i-2)?
            dp[i] = max(dp[i-1], dp[i-2] + nums[start + i]);
        }

        return dp[n-1]; // El último elemento tiene el valor mayor
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Dividimos el círculo en dos escenarios lineales
        return max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
    }
};