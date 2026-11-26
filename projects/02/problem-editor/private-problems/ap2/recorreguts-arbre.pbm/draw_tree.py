import drawsvg
import os


def parse_preorder(it):
    """Build tree from preorder iterator. -1 means null (leaf)."""
    v = next(it, None)
    if v is None or v == -1:
        return None
    left = parse_preorder(it)
    right = parse_preorder(it)
    return {"value": v, "left": left, "right": right}


def assign_layout(node, level, next_x):
    """Assign (level, x_pos) to each node via inorder. Returns next x index."""
    if node is None:
        return next_x
    next_x = assign_layout(node["left"], level + 1, next_x)
    node["level"] = level
    node["x_pos"] = next_x
    next_x += 1
    next_x = assign_layout(node["right"], level + 1, next_x)
    return next_x


def collect_nodes(node, out):
    """Append all nodes to out (any order)."""
    if node is None:
        return
    out.append(node)
    collect_nodes(node["left"], out)
    collect_nodes(node["right"], out)


def draw_tree(preorder, filename):
    """
    Generate an SVG file showing the binary tree given as a preorder traversal.
    -1 values indicate leaves (null); they are not drawn.
    Root at top; same-level nodes on one horizontal line, evenly spaced.
    Single child is shown as left or right as appropriate.
    """
    it = iter(preorder)
    root = parse_preorder(it)
    if root is None:
        # Empty tree: still produce valid SVG
        d = drawsvg.Drawing(100, 100)
        d.save_svg(filename)
        return

    assign_layout(root, 0, 0)
    nodes = []
    collect_nodes(root, nodes)
    n = len(nodes)
    depth = max(nd["level"] for nd in nodes)

    # Layout constants
    level_height = 70
    node_radius = 18
    margin = 50
    width = max(400, n * 40)
    height = margin * 2 + depth * level_height + node_radius * 2

    x_scale = (width - 2 * margin) / (n - 1) if n > 1 else 0

    def x_coord(x_pos):
        return margin + x_pos * x_scale if n > 1 else width / 2

    def y_coord(level):
        return margin + level * level_height

    d = drawsvg.Drawing(width, height, origin=(0, 0))

    # Draw edges first (under nodes)
    for node in nodes:
        px = x_coord(node["x_pos"])
        py = y_coord(node["level"])
        for child in (node["left"], node["right"]):
            if child is not None:
                cx = x_coord(child["x_pos"])
                cy = y_coord(child["level"])
                d.append(drawsvg.Line(px, py, cx, cy - node_radius,
                                      stroke="black", stroke_width=2))

    # Draw nodes: circle and text
    for node in nodes:
        x = x_coord(node["x_pos"])
        y = y_coord(node["level"])
        d.append(drawsvg.Circle(x, y, node_radius, fill="white", stroke="black", stroke_width=2))
        d.append(drawsvg.Text(str(node["value"]), 14, x, y,
                              font_family="Helvetica", fill="black",
                              text_anchor="middle", dominant_baseline="middle"))

    d.save_svg(filename)


preorder = map(int, "3 0 7 -1 4 -1 -1 2 -1 -1 5 4 -1 -1 7 6 -1 1 -1 -1 -1".split())
draw_tree(preorder, "tree.svg")
os.system("rsvg-convert -f pdf -o tree.pdf tree.svg")