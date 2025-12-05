class Solution {
public:
    // Función auxiliar: Busca caminos que empiezan en el nodo 'node'
    long long countPaths(TreeNode* node, long long targetSum) {
        if (!node) return 0;
        
        long long count = 0;
        
        // Si el valor actual completa la suma, encontramos 1 camino válido
        if (node->val == targetSum) {
            count++;
        }
        
        // Seguimos buscando hacia abajo (izquierda y derecha) restando el valor actual al objetivo
        
        count += countPaths(node->left, targetSum - node->val);
        count += countPaths(node->right, targetSum - node->val);
        
        return count;
    }

    // Función Principal: Recorre todo el árbol probando cada nodo como inicio
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        
        // La suma total es:
        // 1. Caminos que empiezan en la raíz 
        // 2. Caminos que empiezan en cualquier nodo del subárbol izquierdo 
        // 3. Caminos que empiezan en cualquier nodo del subárbol derecho
        return countPaths(root, targetSum) 
             + pathSum(root->left, targetSum) 
             + pathSum(root->right, targetSum);
    }
};