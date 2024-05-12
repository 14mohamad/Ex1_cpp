### `Algorithms.hpp`

1. **`isConnected(const Graph& g) -> bool`**:

   - בודק אם הגרף הנתון `g` מחובר.
   - הוא משתמש באלגוריתם חיפוש עומק ראשון (DFS) כדי לעבור את הגרף מכל קודקוד ולבדוק אם כל הקודקודים נגישים זה מזה.

2. **`shortestPath(const Graph& g, int start, int end) -> std::string`**:

   - מוצא את הנתיב הקצר ביותר בין שני קודקודים (`התחלה` ו`סוף`) בגרף הנתון `g`.
   - הוא משתמש באלגוריתם Breadth-First Search (BFS) כדי לעבור את הגרף מקודקוד ההתחלה כדי למצוא את הנתיב הקצר ביותר לקודקוד היעד.

3. **`isContainsCycle(const Graph&g) -> bool`**:

   - בודק אם הגרף הנתון 'g' מכיל מחזור כלשהו.
   - הוא משתמש באלגוריתם של חיפוש עומק-ראשון (DFS) כדי לעבור את הגרף ומזהה מחזור אם נתקלים בקצה אחורי.

4. **`isBipartite(const Graph& g) -> std::string`**:

   - בודק אם הגרף הנתון 'g' הוא דו-חלקי.
   - הוא משתמש באלגוריתם BFS כדי להקצות צבעים (שני צבעים: 0 ו-1) לקודקודים כך שלאף קודקודים סמוכים אין אותו צבע. אם צביעה כזו אפשרית, הגרף הוא דו-חלקי.

5. **`negativeCycle(const Graph& g) -> bool`**:
   - בודק אם הגרף הנתון 'g' מכיל מחזור שלילי.
   - הוא משתמש באלגוריתם Bellman-Ford כדי לזהות מחזורים שליליים בגרף.

### `Graph.hpp`

1. **`Graph()`**:

   - קונסטרוקטור הבנאי של הגרף .

2. **`~Graph()`**:

   - דיסטרוקטור פירוק הגרף .

3. **`loadGraph(const std::vector<std::vector<int>>& adjacencyMatrix) -> void`**:

   - טוען את הגרף ממטריצת הסמיכות הנתונה.
   - מטריצת הסמיכות מייצגת את הקשרים בין קודקודים, כאשר ערך שאינו אפס ב- `matrix[i][j]` מציין קצה מקודקוד `i` לקודקוד `j`.

4. **`printGraph() const -> void`**:

   - מדפיס את הגרף (למטרות איתור באגים).
   - הוא מדפיס כל קודקוד ואת הקודקודים הסמוכים לו.

5. **`getNumVertices() const -> int`**:

   - מחזירה את מספר הקודקודים בגרף.

6. **`getNumEdges() const -> int`**:

   - מחזירה את מספר הקצוות בגרף.

7. **`containsEdge(unsigned int u, unsigned int v) const -> bool`**:

   - בודק אם יש קצה מקודקוד `u` לקודקוד `v`.

8. **`getNeighbors(unsigned int u, int& size) const -> int*`**:

   - מחזירה מערך של שכנים של קודקוד 'u'.
   - הפרמטר 'גודל' משמש לאחסון גודל המערך המוחזר.

9. **`getWeight(unsigned int u, unsigned int v) const -> int`**:
   - מחזיר את משקל הקצה מקודקוד `u` לקודקוד `v`.

### `Algorithms.cpp`

1. **`traverseGraph(const Graph &g, unsigned int u, bool visited[]) -> void`**:

   - פונקציית עוזר המשמשת את `isConnected()` לביצוע חיפוש עומק-ראשון (DFS) של הגרף החל מקודקוד `u`.
   - הוא מסמן קודקודים שביקרו באמצעות מערך ה'ביקורים'.

2. **`isConnected(const Graph &g) -> bool`**:

   - בודק אם הגרף הנתון `g` מחובר.
   - הוא משתמש באלגוריתם DFS על כל הקודקודים כדי להבטיח שכל קודקוד נגיש מכל קודקוד אחר.

3. **`shortestPath(const Graph &g, int start, int end) -> std::string`**:

   - מוצא את הנתיב הקצר ביותר בין קודקודים 'התחלה' ו'סוף' בגרף הנתון 'g'.
   - הוא משתמש באלגוריתם Breadth-First Search (BFS) כדי לעבור את הגרף ולמצוא את הנתיב הקצר ביותר.

4. **`isContainsCycle(const Graph &g) -> bool`**:

   - בודק אם הגרף הנתון 'g' מכיל מחזור כלשהו.
   - הוא משתמש באלגוריתם של Depth-First Search (DFS) ובפונקציית עוזר `isContainsCycleUtil()` כדי לזהות מחזורים בגרף.

5. **`isContainsCycleUtil(const Graph &g, int v, std::vector<bool> &visited, std::vector<int> &parent) -> bool`**:

   - פונקציית עוזר המשמשת את `isContainsCycle()` לביצוע חציית DFS וזיהוי מחזורים בגרף.
   - הוא עוקב אחר קודקודים ביקרו והוריהם כדי לזהות קצוות אחוריים.

6. **`isBipartite(const Graph &g) -> std::string`**:

   - בודק אם הגרף הנתון 'g' הוא דו-חלקי.
   - הוא משתמש באלגוריתם BFS כדי להקצות צבעים (0 ו-1) לקודקודים וקובע אם לקודקודים סמוכים יש צבעים שונים.

7. **`negativeCycle(const Graph &g) -> bool`**:
   - בודק אם הגרף הנתון 'g' מכיל מחזור שלילי.
   - הוא משתמש באלגוריתם Bellman-Ford כדי לזהות מחזורים שליליים בגרף.

### `Graph.cpp`

1. **`Graph::Graph()`:**

   - קונסטרוקטור הבנאי של הגרף .

2. **`Graph::~Graph()`:**

   - דיסטרוקטור פירוק הגרף .

3. **`Graph::loadGraph(const std::vector<std::vector<int>> &adjacencyMatrix) -> void`:**

   - טוען את הגרף ממטריצת הסמיכות הנתונה.
   - מאמת את המטריצה כדי להבטיח שהיא מייצגת מבנה גרף חוקי.

4. **`Graph::printGraph() const -> void`:**

   - מדפיס את הגרף (למטרות איתור באגים).
   - פלט כל קודקוד והקודקודים הסמוכים לו.

5. **`Graph::getNumVertices() const -> int`:**

   - מחזירה את מספר הקודקודים בגרף.

6. **`Graph::getNumEdges() const -> int`:**

   - מחזירה את מספר הקצוות בגרף.

7. **`Graph::containsEdge(unsigned int u, unsigned int v) const -> bool`:**

   - בודק אם יש קצה מקודקוד `u` לקודקוד `v`.

8. **`Graph::getNeighbors(unsigned int u, int &size) const -> int*`:**

   - מחזירה מערך של שכנים של קודקוד 'u'.
   - הפרמטר 'גודל' משמש לאחסון גודל המערך המוחזר.

9. **`Graph::getWeight(unsigned int u, unsigned int v) const -> int`:**
   - מחזיר את משקל הקצה מקודקוד `u` לקודקוד `v`.
