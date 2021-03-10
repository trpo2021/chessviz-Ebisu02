
// for black figure's
$(".p").click(function(event) {
    alert("Test");
    event.preventDefault();
});

// for white figure's
$(".P").click(function(event) {
    alert("Test");
    event.preventDefault();
});

// Movement for P figure 
function onDragStart(event) {
    event
        .dataTransfer
        .setData('text/plain', event.target.id);
    
    event
        .currentTarget
        .style
        .backgroundColor = "";
}

function onDragOver(event) {
    event.preventDefault();
}

function onDrop(event) {
    const id = event
        .dataTransfer
        .getData('text');

    const draggableElement = document.getElementById(id);
    const dropzone = event.target;

    dropzone.appendChild(draggableElement);

    event   
        .dataTransfer
        .clearData();
}

$(".p").onclick(onDragStart(drag));

