var main_ids = ["waybreak"]

function mainTab(_str){
    // for all sections by id, hide them
    for (i=0;i<page_ids.length;i++){
        document.getElementById(main_ids[i]).hidden = true;
    }
    document.getElementById(_str).hidden = false;
}

var waybreak_ids = ["home", "terrain"]

function waybreakTab(_str){
    // for all sections by id, hide them
    for (i=0;i<waybreak_ids.length;i++){
        document.getElementById(waybreak_ids[i]).hidden = true;
    }
    document.getElementById(_str).hidden = false;
}