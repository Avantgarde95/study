function getTime() {
    return performance.now();
}

function measureJob(job) {
    const startTime = getTime();
    job();
    const endTime = getTime();

    // Get the seconds.
    return (endTime - startTime) / 1000.0;
}

function measureAndPrintJob(name, job) {
    console.log(`# ${name}`);
    const elapsedTime = measureJob(job);
    console.log(`: ${elapsedTime}s\n`);
}

module.exports = {
    getTime,
    measureJob,
    measureAndPrintJob
};
