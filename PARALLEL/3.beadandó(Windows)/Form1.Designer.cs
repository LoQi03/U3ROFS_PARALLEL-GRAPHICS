namespace _3.beadandó_Windows_
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.data = new System.Windows.Forms.DataGridView();
            this.UseButton = new System.Windows.Forms.Button();
            this.SortGroup = new System.Windows.Forms.GroupBox();
            this.name = new System.Windows.Forms.RadioButton();
            this.age = new System.Windows.Forms.RadioButton();
            this.city = new System.Windows.Forms.RadioButton();
            this.id = new System.Windows.Forms.RadioButton();
            this.email = new System.Windows.Forms.RadioButton();
            this.timeLabel = new System.Windows.Forms.Label();
            this.IsParallel = new System.Windows.Forms.GroupBox();
            this.IsParallelTrue = new System.Windows.Forms.RadioButton();
            this.IsParallelFalse = new System.Windows.Forms.RadioButton();
            this.SearchButton = new System.Windows.Forms.Button();
            this.SearcField = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.data)).BeginInit();
            this.SortGroup.SuspendLayout();
            this.IsParallel.SuspendLayout();
            this.SuspendLayout();
            // 
            // data
            // 
            this.data.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.data.Location = new System.Drawing.Point(12, 175);
            this.data.Name = "data";
            this.data.ReadOnly = true;
            this.data.Size = new System.Drawing.Size(1205, 444);
            this.data.TabIndex = 0;
            // 
            // UseButton
            // 
            this.UseButton.Location = new System.Drawing.Point(12, 12);
            this.UseButton.Name = "UseButton";
            this.UseButton.Size = new System.Drawing.Size(100, 31);
            this.UseButton.TabIndex = 1;
            this.UseButton.Text = "Use";
            this.UseButton.UseVisualStyleBackColor = true;
            this.UseButton.Click += new System.EventHandler(this.UseButton_Click);
            // 
            // SortGroup
            // 
            this.SortGroup.Controls.Add(this.email);
            this.SortGroup.Controls.Add(this.id);
            this.SortGroup.Controls.Add(this.city);
            this.SortGroup.Controls.Add(this.age);
            this.SortGroup.Controls.Add(this.name);
            this.SortGroup.Location = new System.Drawing.Point(125, 2);
            this.SortGroup.Name = "SortGroup";
            this.SortGroup.Size = new System.Drawing.Size(268, 41);
            this.SortGroup.TabIndex = 2;
            this.SortGroup.TabStop = false;
            this.SortGroup.Text = "SortBy";
            // 
            // name
            // 
            this.name.AutoSize = true;
            this.name.Location = new System.Drawing.Point(46, 17);
            this.name.Name = "name";
            this.name.Size = new System.Drawing.Size(53, 17);
            this.name.TabIndex = 0;
            this.name.TabStop = true;
            this.name.Text = "Name";
            this.name.UseVisualStyleBackColor = true;
            // 
            // age
            // 
            this.age.AutoSize = true;
            this.age.Location = new System.Drawing.Point(105, 17);
            this.age.Name = "age";
            this.age.Size = new System.Drawing.Size(44, 17);
            this.age.TabIndex = 1;
            this.age.TabStop = true;
            this.age.Text = "Age";
            this.age.UseVisualStyleBackColor = true;
            // 
            // city
            // 
            this.city.AutoSize = true;
            this.city.Location = new System.Drawing.Point(155, 17);
            this.city.Name = "city";
            this.city.Size = new System.Drawing.Size(42, 17);
            this.city.TabIndex = 2;
            this.city.TabStop = true;
            this.city.Text = "City";
            this.city.UseVisualStyleBackColor = true;
            // 
            // id
            // 
            this.id.AutoSize = true;
            this.id.Location = new System.Drawing.Point(6, 17);
            this.id.Name = "id";
            this.id.Size = new System.Drawing.Size(34, 17);
            this.id.TabIndex = 3;
            this.id.TabStop = true;
            this.id.Text = "Id";
            this.id.UseVisualStyleBackColor = true;
            // 
            // email
            // 
            this.email.AutoSize = true;
            this.email.Location = new System.Drawing.Point(203, 17);
            this.email.Name = "email";
            this.email.Size = new System.Drawing.Size(50, 17);
            this.email.TabIndex = 4;
            this.email.TabStop = true;
            this.email.Text = "Email";
            this.email.UseVisualStyleBackColor = true;
            // 
            // timeLabel
            // 
            this.timeLabel.AutoSize = true;
            this.timeLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 27.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.timeLabel.Location = new System.Drawing.Point(12, 116);
            this.timeLabel.Name = "timeLabel";
            this.timeLabel.Size = new System.Drawing.Size(100, 42);
            this.timeLabel.TabIndex = 3;
            this.timeLabel.Text = "Time";
            // 
            // IsParallel
            // 
            this.IsParallel.Controls.Add(this.IsParallelFalse);
            this.IsParallel.Controls.Add(this.IsParallelTrue);
            this.IsParallel.Location = new System.Drawing.Point(125, 62);
            this.IsParallel.Name = "IsParallel";
            this.IsParallel.Size = new System.Drawing.Size(268, 37);
            this.IsParallel.TabIndex = 4;
            this.IsParallel.TabStop = false;
            this.IsParallel.Text = "IsParallel";
            // 
            // IsParallelTrue
            // 
            this.IsParallelTrue.AutoSize = true;
            this.IsParallelTrue.Location = new System.Drawing.Point(14, 14);
            this.IsParallelTrue.Name = "IsParallelTrue";
            this.IsParallelTrue.Size = new System.Drawing.Size(47, 17);
            this.IsParallelTrue.TabIndex = 0;
            this.IsParallelTrue.TabStop = true;
            this.IsParallelTrue.Text = "True";
            this.IsParallelTrue.UseVisualStyleBackColor = true;
            // 
            // IsParallelFalse
            // 
            this.IsParallelFalse.AutoSize = true;
            this.IsParallelFalse.Location = new System.Drawing.Point(168, 14);
            this.IsParallelFalse.Name = "IsParallelFalse";
            this.IsParallelFalse.Size = new System.Drawing.Size(50, 17);
            this.IsParallelFalse.TabIndex = 1;
            this.IsParallelFalse.TabStop = true;
            this.IsParallelFalse.Text = "False";
            this.IsParallelFalse.UseVisualStyleBackColor = true;
            // 
            // SearchButton
            // 
            this.SearchButton.Location = new System.Drawing.Point(421, 12);
            this.SearchButton.Name = "SearchButton";
            this.SearchButton.Size = new System.Drawing.Size(112, 31);
            this.SearchButton.TabIndex = 5;
            this.SearchButton.Text = "Search";
            this.SearchButton.UseVisualStyleBackColor = true;
            this.SearchButton.Click += new System.EventHandler(this.SearchButton_Click);
            // 
            // SearcField
            // 
            this.SearcField.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.SearcField.Location = new System.Drawing.Point(539, 12);
            this.SearcField.Name = "SearcField";
            this.SearcField.Size = new System.Drawing.Size(653, 31);
            this.SearcField.TabIndex = 6;
            this.SearcField.Text = "Search....";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1229, 635);
            this.Controls.Add(this.SearcField);
            this.Controls.Add(this.SearchButton);
            this.Controls.Add(this.IsParallel);
            this.Controls.Add(this.timeLabel);
            this.Controls.Add(this.SortGroup);
            this.Controls.Add(this.UseButton);
            this.Controls.Add(this.data);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.ShowIcon = false;
            this.Text = "DataFinder";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.data)).EndInit();
            this.SortGroup.ResumeLayout(false);
            this.SortGroup.PerformLayout();
            this.IsParallel.ResumeLayout(false);
            this.IsParallel.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView data;
        private System.Windows.Forms.Button UseButton;
        private System.Windows.Forms.GroupBox SortGroup;
        private System.Windows.Forms.RadioButton id;
        private System.Windows.Forms.RadioButton city;
        private System.Windows.Forms.RadioButton age;
        private System.Windows.Forms.RadioButton name;
        private System.Windows.Forms.RadioButton email;
        private System.Windows.Forms.Label timeLabel;
        private System.Windows.Forms.GroupBox IsParallel;
        private System.Windows.Forms.RadioButton IsParallelFalse;
        private System.Windows.Forms.RadioButton IsParallelTrue;
        private System.Windows.Forms.Button SearchButton;
        private System.Windows.Forms.TextBox SearcField;
    }
}

