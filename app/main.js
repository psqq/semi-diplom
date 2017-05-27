const fs = require('fs');
const child_process = require('child_process');

const Koa = require('koa');
const app = new Koa();
const router = require('koa-router')();
const bodyParser = require('koa-bodyparser');

router.get('/', function(ctx, next) {
  ctx.body = fs.readFileSync("index.html", {
    encoding: "utf-8"
  });
});

router.get('/get_image/:id/:time', function(ctx, next) {
  ctx.type = "image/png";
  ctx.body = fs.readFileSync(ctx.params.id + '.png');
});

router.post('/tosemi', function(ctx, next) {
  var g = ctx.request.body["digraph"];
  fs.writeFileSync("tosemi-g.txt", g);
  var cmd = `${__dirname}/semi tos tosemi-g.txt tosemi-s.txt`;
  child_process.execSync(cmd, {
    cwd: __dirname,
    shell: "/bin/bash",
    encoding: "utf-8"
  });
  ctx.body = fs.readFileSync("tosemi-s.txt", {
    encoding: "utf-8"
  });
});

router.post('/iso_simple', function(ctx, next) {
  var data = ctx.request.body;
  fs.writeFileSync("iso_simple-s1.txt", data["s1"]);
  fs.writeFileSync("iso_simple-s2.txt", data["s2"]);
  var cmd =
    `${__dirname}/semi iso -int iso_simple-s1.txt iso_simple-s2.txt`;
  var res = child_process.execSync(cmd, {
    cwd: __dirname,
    shell: "/bin/bash",
    encoding: "utf-8"
  });
  ctx.body = res;
});

router.post('/iso_full', function(ctx, next) {
  var data = ctx.request.body;
  fs.writeFileSync("iso_simple-s1.txt", data["s1"]);
  fs.writeFileSync("iso_simple-s2.txt", data["s2"]);
  var cmd =
    `${__dirname}/semi iso -int -logtofile iso_simple-s1.txt iso_simple-s2.txt`;
  var res = child_process.execSync(cmd, {
    cwd: __dirname,
    shell: "/bin/bash",
    encoding: "utf-8"
  });
  // console.log("res == ", res);
  ctx.body = fs.readFileSync("log.txt", {
    encoding: "utf-8"
  });
});

const VIZ_VALID_IDS = ["g1", "g2", "g1_G1", "g1_G2", "g2_G1", "g2_G2"];

router.post('/viz', function(ctx, next) {
  var g = ctx.request.body["digraph"];
  var id = ctx.request.body["id"];
  if (id == undefined) {
    id = "g";
  } else {
    var flag = true;
    for (var valid_id of VIZ_VALID_IDS) {
      if (valid_id == id) {
        flag = false;
        break;
      }
    }
    if (flag) {
      console.log(`Error: invalid id: ${id}`);
      return;
    }
  }
  var gfn = `viz-${id}.txt`,
    dotfn = `viz-${id}.dot`,
    pngfn = `viz-${id}.png`;
  fs.writeFileSync(gfn, g);
  child_process.execSync(`${__dirname}/semi todot ${gfn} ${dotfn}`, {
    cwd: __dirname,
    shell: "/bin/bash",
  });
  child_process.execSync(`dot -Tpng -o ${pngfn} ${dotfn}`, {
    cwd: __dirname,
    shell: "/bin/bash"
  });
  ctx.body = `viz-${id}/${Date.now()}`;
});

app.use(bodyParser());

app
  .use(router.routes())
  .use(router.allowedMethods());

app.listen(3497);
console.log('local link: http://localhost:3497');
