    list< vector<string> >::iterator list_it;
    vector<string>::iterator vec_it;
    for (list_it = test.begin(); list_it != test.end(); ++ list_it){
     for (vec_it = list_it->begin(); vec_it != list_it->end(); ++ vec_it)
     {
          //do something with vec_it
          //for example call member function of Class
          std::cout<< (*vec_it) << std::endl;
     } }