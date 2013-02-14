Finucane's Unified Data Model (FUDM)
====================================
Finucane's Unified Data Model is an open collection of abstract data types and containers which are designed to facilitate both the exchange of data between applications, and the retrieval of data from implementation independent *archives*. Furthermore, FUDM allows for complex data structures to retrieve **potentially** relevant data that has been stored in an archive as named *datum fields*. Within the data model, such a complex data structure **is an** *archivable* type, and, as such, must define methods for both composing and decomposing itself from a collection (vector) of datum fields. Furthermore, the archive stores and retrieves datum fields as collections which are connected by the *UUID* of the archivable object from which they originated (caveat: originated **as of the last decomposition and storage in the archive**).

While FUDM strives to be a simple, but complete framework on which larger programs and applications can be built, FUDM also strives to provide an abundant pool of ready-made concrete archive types (e.g., in-memory/volatile, simple file implementation(s), and database implementations), archive types, and supplementary classes/routines for common operations.

Links
-----
-http://finucaneresearch.wordpress.org
-http://www.finucaneresearch.net

