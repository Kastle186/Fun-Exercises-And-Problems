const layouts = {
  layout1: [
    { x: 10, y: 10, width: 100, height: 50 },
    { x: 120, y: 10, width: 50, height: 100 }
  ],
  layout2: [
    { x: 20, y: 20, width: 80, height: 80 }
  ],
  // Add more layouts here
};

<img src="thumb1.png" data-layout-id="layout1" class="thumbnail" />
<img src="thumb2.png" data-layout-id="layout2" class="thumbnail" />

document.querySelectorAll('.thumbnail').forEach(thumb => {
  thumb.addEventListener('click', (event) => {
    const layoutId = event.target.dataset.layoutId;
    const rectangles = layouts[layoutId];
    if (rectangles) {
      drawRectangles(rectangles);
    }
  });
});

function drawRectangles(rects) {
  const canvas = document.getElementById('myCanvas');
  const ctx = canvas.getContext('2d');
  ctx.clearRect(0, 0, canvas.width, canvas.height);

  rects.forEach(rect => {
    ctx.strokeRect(rect.x, rect.y, rect.width, rect.height);
  });
}
