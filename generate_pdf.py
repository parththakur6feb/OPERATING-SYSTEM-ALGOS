from fpdf import FPDF

class PDF(FPDF):
    def header(self):
        self.set_font("Arial", 'B', 12)
        self.cell(0, 10, 'Operating System Algorithms', 0, 1, 'C')

    def chapter_title(self, title):
        self.set_font("Arial", 'B', 12)
        self.cell(0, 10, title, 0, 1, 'L')
        self.ln(5)

    def chapter_body(self, body):
        self.set_font("Arial", '', 12)
        self.multi_cell(0, 10, body)
        self.ln()

pdf = PDF()
pdf.add_page()

algorithms = {
    "First-Come, First-Served (FCFS)": "The simplest scheduling algorithm, where the process that arrives first gets executed first.",
    "Shortest Job Next (SJN)": "A non-preemptive scheduling algorithm that selects the process with the smallest execution time.",
    "Round Robin (RR)": "A preemptive scheduling algorithm that assigns a fixed time unit to each process in a cyclic manner.",
    "Priority Scheduling": "Processes are scheduled based on their priority. High priority processes are executed first.",
    "Multilevel Queue Scheduling": "Processes are divided into multiple queues based on their priority levels, and each queue has its own scheduling algorithm."
}

for title, description in algorithms.items():
    pdf.chapter_title(title)
    pdf.chapter_body(description)

pdf.output("Operating_System_Algorithms.pdf")