DigrafoPonderado* grafo = new DigrafoPonderado(3);
    grafo->asignarCodigoAVertice(0, "AAA");
    grafo->asignarCodigoAVertice(1, "BBB");
    grafo->asignarCodigoAVertice(2, "CCC");
    grafo->agregarArista("AAA", "BBB", 1, 2.0);
    grafo->agregarArista("CCC", "BBB", 5, 20.0);
    grafo->agregarArista("CCC", "AAA", 10, 5.0);
    grafo->mostrarListaAdyacencia();