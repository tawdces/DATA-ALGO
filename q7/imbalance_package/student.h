// Your code here
KeyT bestKey;
int maxImbalance;
bool first;

int dfs(node* n) {
    if (n == NULL) return -1;

    int hl = dfs(n->left);
    int hr = dfs(n->right);

    int diff = hl - hr;
    if (diff < 0) diff = -diff;

    if (first || diff > maxImbalance ||
        (diff == maxImbalance && n->data.first < bestKey)) {
        maxImbalance = diff;
        bestKey = n->data.first;
        first = false;
    }

    return (hl > hr ? hl : hr) + 1;
}

KeyT getValueOfMostImbalanceNode() {
    // Your code here
    first = true;
    maxImbalance = -1;
    dfs(mRoot);
    return bestKey;
}
