imgLandscape.addEventListener("click", drawLayout);
imgPortrait.addEventListener("click", drawLayout);

function drawLayout() {
    currentLayout = "2x2"; // Set current layout

    const ctx = canvas.getContext("2d");
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    const rows = 2;
    const cols = 2;

    const cellWidth = canvas.width / cols;
    const cellHeight = canvas.height / rows;

    ctx.strokeStyle = "#333";
    ctx.lineWidth = 2;

    for (let row = 0; row < rows; row++) {
        for (let col = 0; col < cols; col++) {
            const x = col * cellWidth;
            const y = row * cellHeight;
            ctx.strokeRect(x, y, cellWidth, cellHeight);
        }
    }
}

let currentLayout = null; // Track what layout is currently selected

function resizeCanvas(width, height)
{
    canvas.width = width;
    canvas.height = height;

    document.documentElement.style.setProperty("--canvas-width", width + "px");
    document.documentElement.style.setProperty("--canvas-height", height + "px");

    if (currentLayout) {
        drawLayout(currentLayout); // Redraw after resizing
    }
}
