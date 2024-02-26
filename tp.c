void insertion_sort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}






void selectionSort(int arr[], int n) 
{    int opcount=0;
    int i, j, min_idx; 

    for (i = 0; i < n-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
        opcount++;
        if (arr[j] < arr[min_idx]) 
            min_idx = j; 

        if(min_idx != i) 
            swap(&arr[min_idx], &arr[i]); 
    } 
     printf("\nOperation Count %d\n",opcount);
} 




int bubbleSort(int a[], int n) {
    int i, j, temp, count = 0;
    for (i=0; i < n-1; i++) {
        for (j=0; j < n-i-1; j++) {
            count++;
            if (a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    return count;
}






void mergeSort(int arr[], int left, int right) {

    if (arr == NULL || left >= right)
        return;

    int mid = (left + right) / 2;

    if (left < mid)
        mergeSort(arr, left, mid);

    if (mid + 1 < right)
        mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

void merge(int arr[], int left, int mid, int right) {

    if (left >= right || arr == NULL)
        return;

    int * finalArr = (int *) malloc((right - left + 1) * sizeof(int));

    int i = left;
    int j = mid + 1;
    int ind = 0;

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            finalArr[ind++] = arr[i];
            i++;
        } else {
            finalArr[ind++] = arr[j];
            j++;
        }
    }

    while (i <= mid) {
        finalArr[ind++] = arr[i];
        i++;
    }

    while (j <= right) {
        finalArr[ind++] = arr[j];
        j++;
    }

    ind = 0;
    for (i = left; i <= right; i++)
        arr[i] = finalArr[ind++];

    free(finalArr);
}




int partition(int arr[], int left, int right) {
    int pivot = arr[left];
    int i = left + 1;
    int j = right;
    while (i <= j) {
        while (i <= right && arr[i] <= pivot)
            i++;
        while (j >= left && arr[j] > pivot)
            j--;
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[left];
    arr[left] = arr[j];
    arr[j] = temp;
    return j;
}

void quicksort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = partition(arr, left, right);
        quicksort(arr, left, pivot - 1);
        quicksort(arr, pivot + 1, right);
    }
}





void DFS(struct Graph *graph, int startVertex)
{
    struct Stack *stack = createStack(graph->vertices);

    push(stack, startVertex);

    while (!isStackEmpty(stack))
    {
        int currentVertex = pop(stack);
        if (graph->visited[currentVertex] == 1)
            continue;
        else
        {
            graph->visited[currentVertex] = 1;
            printf("Visited %d \n", currentVertex);
        }

        struct Node *temp = graph->head[currentVertex];
        while (temp != NULL)
        {
            int connectedVertex = temp->dest;

            if (graph->visited[connectedVertex] == 0)
            {
                push(stack, connectedVertex);
                // graph->visited[connectedVertex] = 1;
            }
            temp = temp->next;
        }
    }

    free(stack->array);
    free(stack);
}









void BFS(struct Graph *graph, int startVertex) {
    int queue[1000];
    int front = -1;
    int rear = -1;
    
    graph->visited[startVertex] = 1;
    queue[++rear] = startVertex;

    while (front != rear) {
        int currentVertex = queue[++front];
        printf("Visited %d \n", currentVertex);

        struct Node *temp = graph->head[currentVertex].next;
        while (temp != NULL) {
            int adjVertex = temp->dest;

            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                queue[++rear] = adjVertex;
            }

            temp = temp->next;
        }
    }
}










void topologicalSortUtil(struct Graph *graph, int v, int visited[], int stack[], int *stackIndex) {
    visited[v] = 1;

    struct Node *temp = graph[v].head;
    while (temp != NULL) {
        if (!visited[temp->dest])
            topologicalSortUtil(graph, temp->dest, visited, stack, stackIndex);
        temp = temp->next;
    }

    stack[(*stackIndex)++] = v;
}

void topologicalSort(struct Graph *graph, int numVertices) {
    int *visited = (int *)malloc(numVertices * sizeof(int));
    int *stack = (int *)malloc(numVertices * sizeof(int));
    int stackIndex = 0;

    for (int i = 0; i < numVertices; i++)
        visited[i] = 0;

    for (int i = 0; i < numVertices; i++)
        if (!visited[i])
            topologicalSortUtil(graph, i, visited, stack, &stackIndex);

    // Print the result
    printf("Topological Sort: ");
    for (int i = stackIndex - 1; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");

    free(visited);
    free(stack);
}






void topologicalSort(struct Graph *graph, int numVertices) {
    int *inDegree = (int *)malloc(numVertices * sizeof(int));

    for (int i = 0; i < numVertices; i++)
        inDegree[i] = 0;

    for (int i = 0; i < numVertices; i++) {
        struct Node *ptr = graph[i].head;
        while (ptr != NULL) {
            inDegree[ptr->dest]++;
            ptr = ptr->next;
        }
    }

    // Create a queue to store nodes with in-degree 0
    int *queue = (int *)malloc(numVertices * sizeof(int));
    int front = 0, rear = 0;

    // Enqueue nodes with in-degree 0
    for (int i = 0; i < numVertices; i++) {
        if (inDegree[i] == 0)
            queue[rear++] = i;
    }

    // Perform source removal using a queue
    while (front < rear) {
        int current = queue[front++];

        printf("%d ", current);

        struct Node *ptr = graph[current].head;
        while (ptr != NULL) {
            // Decrement the in-degree of the adjacent vertices
            inDegree[ptr->dest]--;

            // If in-degree becomes 0, enqueue the vertex
            if (inDegree[ptr->dest] == 0)
                queue[rear++] = ptr->dest;

            ptr = ptr->next;
        }
    }

    printf("\n");

    free(inDegree);
    free(queue);
}






bt* findCCA(bt* root, int n1, int n2, int* nodeCount) {
    if (root == NULL) {
        return NULL;
    }

    (*nodeCount)++; 

    if (root->data == n1 || root->data == n2) {
        return root;
    }

    bt* leftCCA = findCCA(root->left, n1, n2, nodeCount);
    bt* rightCCA = findCCA(root->right, n1, n2, nodeCount);

    if (leftCCA != NULL && rightCCA != NULL) {
        return root;
    }

    return (leftCCA != NULL) ? leftCCA : rightCCA;
}