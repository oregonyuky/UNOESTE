let animationId;

function drawTriangle(ctx, x, y, size, color) {
	ctx.fillStyle = color;
	ctx.beginPath();
	ctx.moveTo(x, y);
	ctx.lineTo(x + size, y);
	ctx.lineTo(x + size / 2, y - Math.sin(Math.PI / 3) * size);
	ctx.closePath();
	ctx.fill();
}

function sierpinski(ctx, x, y, size, depth) {
	if (depth === 0) {
		let gradient = ctx.createLinearGradient(
			x,
			y - Math.sin(Math.PI / 3) * size,
			x + size,
			y
		);
		gradient.addColorStop(0, "red");
		gradient.addColorStop(0.7, "yellow");
		gradient.addColorStop(1, "green");
		drawTriangle(ctx, x, y, size, gradient);
	} else {
		let newSize = size / 2;
		sierpinski(ctx, x, y, newSize, depth - 1);
		sierpinski(ctx, x + newSize, y, newSize, depth - 1);
		sierpinski(
			ctx,
			x + newSize / 2,
			y - Math.sin(Math.PI / 3) * newSize,
			newSize,
			depth - 1
		);
	}
}

function draw() {
	const canvas = document.getElementById("canvas");
	const ctx = canvas.getContext("2d");
	ctx.clearRect(0, 0, canvas.width, canvas.height);

	let depth = parseInt(document.getElementById("iterations").value);
	let size = canvas.width * 0.8;
	let startX = (canvas.width - size) / 2;
	let startY = (canvas.height + Math.sin(Math.PI / 3) * size) / 2;

	sierpinski(ctx, startX, startY, size, depth);

	animationId = requestAnimationFrame(draw);
}

document.getElementById("iterations").addEventListener("input", function () {
	document.getElementById("iterations-value").textContent = this.value;
});

window.onload = () => {
	draw();
};

window.onunload = () => {
	cancelAnimationFrame(animationId);
};
